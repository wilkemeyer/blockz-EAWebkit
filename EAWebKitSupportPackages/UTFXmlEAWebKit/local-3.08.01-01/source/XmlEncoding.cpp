/*
Copyright (C) 2009, 2010, 2012 Electronic Arts, Inc.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1.  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
2.  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
3.  Neither the name of Electronic Arts, Inc. ("EA") nor the names of
    its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY ELECTRONIC ARTS AND ITS CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ELECTRONIC ARTS OR ITS CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/



#include <EABase/eabase.h>
#include <UTFXml/internal/Config.h>
#include <UTFXml/XmlEncoding.h>
#include <EAIO/EAStream.h>
#include <string.h>
#include EA_ASSERT_HEADER

#define LOCAL_MIN(x,y) ((x) < (y) ? (x) : (y))
#define LOCAL_MAX(x,y) ((x) > (y) ? (x) : (y))

#ifdef _MSC_VER
    #pragma warning(push)
    #pragma warning(disable: 4127)  // conditional expression is constant.
#endif



namespace EA
{
namespace XML
{


//static int GetReadEncodingCharSize(ReadEncoding r)
//{
//    if(r == kReadEncodingUTF8)
//        return 1;
//    return 2;
//    To do: support 4 byte types when ReadEncoding acquires such a type.
//}


static int GetWriteEncodingCharSize(WriteEncoding w)
{
    if(w == kWriteEncodingUTF16)
        return 2;
    else if(w == kWriteEncodingUCS4)
        return 4;
    return 1;
}



UTFXML_API
bool WriteEncoded(EA::IO::IStream* pDestination, const char8_t* pSourceText, size_t nSourceWriteCount, 
                  WriteEncoding srcEncoding, WriteEncoding destEncoding)
{
    while(nSourceWriteCount > 0)
    {
        uint8_t encoded[256];
        size_t  bufferSize = 256;

        size_t nCharCount = ConvertEncoding(pSourceText, nSourceWriteCount, srcEncoding,
                                            encoded, bufferSize, destEncoding);

        nSourceWriteCount -= nCharCount;
        pSourceText += nCharCount;

        if(!pDestination->Write(encoded, bufferSize))
            return false;
    }

    return true;
}


UTFXML_API
bool WriteEncoded(EA::IO::IStream* pDestination, const char16_t* pSourceText, size_t nSourceWriteCount, 
                  WriteEncoding destEncoding)
{
    while(nSourceWriteCount > 0)
    {
        uint8_t encoded[256];
        size_t  bufferSize = 256;

        size_t nCharCount = ConvertEncoding(pSourceText, nSourceWriteCount, kWriteEncodingUTF16,
                                            encoded, bufferSize, destEncoding);

        nSourceWriteCount -= nCharCount;
        pSourceText += nCharCount;

        if(!pDestination->Write(encoded, bufferSize))
            return false;
    }

    return true;
}


UTFXML_API
bool WriteEncoded(EA::IO::IStream* pDestination, const char32_t* pSourceText, size_t nSourceWriteCount, 
                  WriteEncoding destEncoding)
{
    while(nSourceWriteCount > 0)
    {
        uint8_t encoded[256];
        size_t  bufferSize = 256;

        size_t nCharCount = ConvertEncoding(pSourceText, nSourceWriteCount, kWriteEncodingUCS4,
                                            encoded, bufferSize, destEncoding);

        nSourceWriteCount -= nCharCount;
        pSourceText += nCharCount;

        if(!pDestination->Write(encoded, bufferSize))
            return false;
    }

    return true;
}


///////////////////////////////////////////////////////////////////////////////
// ConvertEncoding
//
// This is a trimmed down version of ConvertEncoding from the 
// UTFFoundation package. It behaves the same as that version.
// We support only UTF8 or UTF16 as input and output types. 
// Note that by supporting UTF8 as an output type, we are for
// all practical purposes supporting ASCII and Latin1, as UTF8
// is a superset of both these types. Thus an nEncodingOutput
// type of ASCII or Latin1 is written as UTF8. It's considered
// the user's fault if the user supplies invalid ASCII or Latin1 chars.
//
UTFXML_API
size_t ConvertEncoding(const void* pTextInput,  size_t  nLengthInput,  WriteEncoding nEncodingInput,
                             void* pTextOutput, size_t& nLengthOutput, WriteEncoding nEncodingOutput)
{
    // Do an early check for empty input.
    if(nLengthInput == 0)
    {
        nLengthOutput = 0;
        return 0;
    }

    const int inputCharSize  = GetWriteEncodingCharSize(nEncodingInput);
    const int outputCharSize = GetWriteEncodingCharSize(nEncodingOutput);

    // If the input code page is MBCS or ASCII or UTF8 but all the characters 
    // in the string are <= 127, then we can do a significant optimization by 
    // just acting as if the input code page is ASCII.
    if(nEncodingInput == kWriteEncodingLatin1)
        nEncodingInput = kWriteEncodingASCII;
    else if(nEncodingInput != kWriteEncodingUTF16) // If input is an 8 bit type...
    {
        bool bInputIsASCII(true);

        for(size_t i(0); i < nLengthInput; i++)
        {
            if(((uint8_t*)pTextInput)[i] > 127)
            {
                bInputIsASCII = false;
                break;
            }
        }

        if(bInputIsASCII)
            nEncodingInput = kWriteEncodingASCII;
    }

    // ASCII <=> ASCII
    // UTF8  <=> UTF8
    // UTF16 <=> UTF16
    // ASCII  => UTF8
    // UTF8  => ASCII (May be impossible to do without losing information)
    if(inputCharSize == outputCharSize)
    {
        if(pTextInput != pTextOutput)
        {
            nLengthInput = LOCAL_MIN(nLengthInput, nLengthOutput);
            if (pTextOutput)
                memcpy(pTextOutput, pTextInput, nLengthInput * outputCharSize);
        }
        nLengthOutput = nLengthInput;
        return nLengthInput;
    }

    // UTF16 => ASCII (May be impossible to do without losing information)
    if(nEncodingInput  == kWriteEncodingUTF16 && 
       nEncodingOutput == kWriteEncodingASCII)
    {
        nLengthInput = LOCAL_MIN(nLengthInput, nLengthOutput);

        if (pTextOutput) {
            uint16_t* pSource16    = (uint16_t*)pTextInput;
            uint8_t*  pDest8       = (uint8_t*)pTextOutput;
            uint16_t* pSource16End = pSource16 + nLengthInput;

            while(pSource16 < pSource16End)
            {
                *pDest8 = (uint8_t)*pSource16; //Intentional possible loss of information here.
                pSource16++;
                pDest8++;
            }
        }

        nLengthOutput = nLengthInput;
        return nLengthInput;
    }

    // UCS4 => ASCII (May be impossible to do without losing information)
    if(nEncodingInput  == kWriteEncodingUCS4 && 
       nEncodingOutput == kWriteEncodingASCII)
    {
        nLengthInput = LOCAL_MIN(nLengthInput, nLengthOutput);

        if (pTextOutput) {
            uint32_t* pSource32    = (uint32_t*)pTextInput;
            uint8_t*  pDest8       = (uint8_t*)pTextOutput;
            uint32_t* pSource32End = pSource32 + nLengthInput;

            while(pSource32 < pSource32End)
            {
                *pDest8 = (uint8_t)*pSource32; //Intentional possible loss of information here.
                pSource32++;
                pDest8++;
            }
        }

        nLengthOutput = nLengthInput;
        return nLengthInput;
    }

    // Note that we put this check *after* the above code. This is because the above
    // code can actually work if the two pointers are the same.
    if(pTextInput == pTextOutput)
        return 0;

    // UTF8 => UTF16
    // UTF8 => UCS4
    if((nEncodingInput == kWriteEncodingUTF8) &&
       ((nEncodingOutput == kWriteEncodingUTF16) || (nEncodingOutput == kWriteEncodingUCS4)))
    {
        // Conversion from UTF8 to UTF16 Unicode. See RFC 2279.
        // We take specific care here to do a proper UTF8 to UTF16 conversion. There are 
        // shorter ways to do the conversion but often these ways introduce potential security 
        // risks into the code because they allow alternative UTF8 forms of strings which 
        // hide the actual string value.
        uint8_t*  pSource8     = (uint8_t*)pTextInput;
        uint16_t* pDest16      = (uint16_t*)pTextOutput;        // Written to if kWriteEncodingUTF16.
        uint32_t* pDest32      = (uint32_t*)pTextOutput;        // Written to if kWriteEncodingUCS4.
        uint8_t*  pSource8End  = pSource8 + nLengthInput;
        uint16_t* pDest16End   = pDest16  + nLengthOutput;

        while((pSource8 < pSource8End) && (pDest16 < pDest16End)) // We use pDest16/pDestEnd16 even if our write format is UCCS4 (char32_t), as all that matters is the write length.
        {
            uint16_t nCharOut;

            if(pSource8[0] < 0x80)         // If 1 input char results in 1 output char...
            {
                nCharOut = pSource8[0];    // This is the case for all ASCII chars.
                ++pSource8;                // We increment 'pDest16' at the bottom of the loop.
            }
            else if(pSource8[0] < 0xC2)
                break; // The character is invalid. It is important that we check for this because various security issues potentially arise if we don't.
            else if(pSource8[0] < 0xE0) // If 2 input chars result in 1 output char...
            {
                if(pSource8End - pSource8 >= 2)
                {
                    if(!((pSource8[1] ^ 0x80) < 0x40))
                        break; // The character is invalid. It is important that we check for this because various security issues potentially arise if we don't.
                    nCharOut  = (uint16_t)(((unsigned)(pSource8[0] & 0x1F) << 6) |
                                           ((unsigned)(pSource8[1] ^ 0x80)));
                    pSource8 += 2; // We increment 'pDest16' at the bottom of the loop.
                }
                else
                    break; // The input string is not long enough to finish reading the current character.
            }
            else if(pSource8[0] < 0xF0) // If 3 input chars result in 1 output char...
            {
                if(pSource8End - pSource8 >= 3)
                {
                    if(!(((pSource8[1] ^ 0x80) < 0x40) &&
                         ((pSource8[2] ^ 0x80) < 0x40) &&
                          (pSource8[0] >= 0xE1 || pSource8[1] >= 0xA0)))
                    {
                        break; // The character is invalid. It is important that we check for this because various security issues potentially arise if we don't.
                    }
                    nCharOut  = (uint16_t)(((unsigned)(pSource8[0] & 0x0F) << 12) |
                                           ((unsigned)(pSource8[1] ^ 0x80) << 6)  |
                                           ((unsigned)(pSource8[2] ^ 0x80)));
                    pSource8 += 3; // We increment 'pDest16' at the bottom of the loop.
                }
                else
                    break; // The input string is not long enough to finish reading the current character.
            }
            else if(pSource8[0] < 0xF8) // If 4 input chars result in 1 output char...
            {
                if(pSource8End - pSource8 >= 4)
                {
                    if(!(((pSource8[1] ^ 0x80) < 0x40) &&
                         ((pSource8[2] ^ 0x80) < 0x40) &&
                         ((pSource8[3] ^ 0x80) < 0x40) &&
                          (pSource8[0] >= 0xF1 || pSource8[1] >= 0x90)))
                    {
                        break; // The character is invalid. It is important that we check for this because various security issues potentially arise if we don't.
                    }
                    nCharOut  = (uint16_t)(((unsigned)(pSource8[0] & 0x07) << 18) |
                                          ((unsigned)(pSource8[1] ^ 0x80) << 12) |
                                          ((unsigned)(pSource8[2] ^ 0x80) << 6)  |
                                          ((unsigned)(pSource8[3] ^ 0x80)));
                    pSource8 += 4; // We increment 'pDest16' at the bottom of the loop.
                }
                else
                    break; // The input string is not long enough to finish reading the current character.
            }
            else //Else the current input char is invalid.
                break;

            if(pTextOutput) 
            {
                if(nEncodingOutput == kWriteEncodingUTF16) 
                    *pDest16 = nCharOut;
                else
                    *pDest32 = nCharOut;
            }

            pDest16++;
            pDest32++;
        }

        nLengthInput  = (uintptr_t)(pSource8 - (uint8_t*)pTextInput);
        nLengthOutput = (uintptr_t)(pDest16  - (uint16_t*)pTextOutput); // It doesn't matter if our output format is UCS4, as nLengthOutput is the same either way.

        return nLengthInput;
    }


    // UTF16 => UTF8
    if(((nEncodingInput == kWriteEncodingUTF16) || (nEncodingInput == kWriteEncodingUCS4)) &&
       (nEncodingOutput == kWriteEncodingUTF8))
    {
        // Conversion from UTF16 to UTF8 Unicode. See RFC 2279.
        uint16_t* pSource16    = (uint16_t*)pTextInput;         // We read from this if nEncodingInput == kWriteEncodingUTF16.
        uint32_t* pSource32    = (uint32_t*)pTextInput;         // We read from this if nEncodingInput == kWriteEncodingUCS4.
        uint8_t*  pDest8       = (uint8_t*)pTextOutput;
        uint16_t* pSource16End = pSource16 + nLengthInput;
        uint8_t*  pDest8End    = pDest8 + nLengthOutput;

        while(pSource16 < pSource16End) // If doesn't matter if we are using UCS4, this length is the same.
        {
            size_t   nBytesToWrite(0);
            uint32_t ch = (nEncodingInput == kWriteEncodingUTF16) ? *pSource16 : *pSource32;

            if(ch < 0x80)
                nBytesToWrite = 1;
            else if(ch < 0x800)
                nBytesToWrite = 2;
            else if(ch < 0x10000)
                nBytesToWrite = 3;
            else if(ch < 0x200000)
                nBytesToWrite = 4;
            else if(ch < 0x4000000)
                nBytesToWrite = 5;
            else if(ch <= 0x7FFFFFFF)
                nBytesToWrite = 6;
            else // else ch is invalid.
                break;

            if((pDest8 + nBytesToWrite) > pDest8End)
                break;

            if (pTextOutput)
            {
                switch(nBytesToWrite) { 
                    case 6: pDest8[5] = (uint8_t)(0x80 | (ch & 0x3F)); ch >>= 6; ch |= 0x4000000; // Fall through
                    case 5: pDest8[4] = (uint8_t)(0x80 | (ch & 0x3F)); ch >>= 6; ch |= 0x200000;  // Fall through
                    case 4: pDest8[3] = (uint8_t)(0x80 | (ch & 0x3F)); ch >>= 6; ch |= 0x10000;   // Fall through
                    case 3: pDest8[2] = (uint8_t)(0x80 | (ch & 0x3F)); ch >>= 6; ch |= 0x800;     // Fall through
                    case 2: pDest8[1] = (uint8_t)(0x80 | (ch & 0x3F)); ch >>= 6; ch |= 0xc0;      // Fall through
                    case 1: pDest8[0] = (uint8_t)(ch);
                };
            }

            pDest8 += nBytesToWrite;
            pSource16++;
            pSource32++;
        }

        nLengthInput  = (uintptr_t)(pSource16 - (uint16_t*)pTextInput); // If doesn't matter if we are using UCS4, this length is the same.
        nLengthOutput = (uintptr_t)(pDest8    - (uint8_t*)pTextOutput);

        return nLengthInput;
    }

    // ASCII => UTF16
    if(nEncodingInput  == kWriteEncodingASCII &&
       nEncodingOutput == kWriteEncodingUTF16)
    {
        // For ASCII to unicode conversions, we can make a very fast version ourselves.
        uint16_t* pTextOutputCurrent = (uint16_t*)pTextOutput;
        nLengthInput = LOCAL_MIN(nLengthInput, nLengthOutput);

        if (pTextOutput) {
            for(size_t i(0); i < nLengthInput; i++, pTextOutputCurrent++)
                *pTextOutputCurrent = *((const uint8_t*)pTextInput+i);
        }

        nLengthOutput = nLengthInput;
        return nLengthInput;
    }

    // ASCII => UCS4
    if(nEncodingInput  == kWriteEncodingASCII &&
       nEncodingOutput == kWriteEncodingUCS4)
    {
        // For ASCII to unicode conversions, we can make a very fast version ourselves.
        uint32_t* pTextOutputCurrent = (uint32_t*)pTextOutput;
        nLengthInput = LOCAL_MIN(nLengthInput, nLengthOutput);

        if (pTextOutput) {
            for(size_t i(0); i < nLengthInput; i++, pTextOutputCurrent++)
                *pTextOutputCurrent = *((const uint8_t*)pTextInput+i);
        }

        nLengthOutput = nLengthInput;
        return nLengthInput;
    }

    return 0;
}



} // namespace XML

} // namespace EA


#undef LOCAL_MIN
#undef LOCAL_MAX

#ifdef _MSC_VER
    #pragma warning(pop)
#endif






