// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


InspectorBackendStub = function()
{
    this._lastCallbackId = 1;
    this._pendingResponsesCount = 0;
    this._callbacks = {};
    this._domainDispatchers = {};
    this._eventArgs = {};
    this._registerDelegate('{"method": "Page.addScriptToEvaluateOnLoad", "params": {"scriptSource": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Page.removeAllScriptsToEvaluateOnLoad", "id": 0}');
    this._registerDelegate('{"method": "Page.reload", "params": {"ignoreCache": {"optional": true , "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Page.open", "params": {"url": {"optional": false, "type": "string"},"newWindow": {"optional": true , "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Page.getCookies", "id": 0}');
    this._registerDelegate('{"method": "Page.deleteCookie", "params": {"cookieName": {"optional": false, "type": "string"},"domain": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Page.getResourceTree", "id": 0}');
    this._registerDelegate('{"method": "Page.getResourceContent", "params": {"frameId": {"optional": false, "type": "string"},"url": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Page.searchInResources", "params": {"text": {"optional": false, "type": "string"},"caseSensitive": {"optional": true , "type": "boolean"},"isRegex": {"optional": true , "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Runtime.evaluate", "params": {"expression": {"optional": false, "type": "string"},"objectGroup": {"optional": true , "type": "string"},"includeCommandLineAPI": {"optional": true , "type": "boolean"},"doNotPauseOnExceptions": {"optional": true , "type": "boolean"},"frameId": {"optional": true , "type": "string"},"returnByValue": {"optional": true , "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Runtime.callFunctionOn", "params": {"objectId": {"optional": false, "type": "string"},"functionDeclaration": {"optional": false, "type": "string"},"arguments": {"optional": true , "type": "object"},"returnByValue": {"optional": true , "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Runtime.getProperties", "params": {"objectId": {"optional": false, "type": "string"},"ownProperties": {"optional": true , "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Runtime.releaseObject", "params": {"objectId": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Runtime.releaseObjectGroup", "params": {"objectGroup": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Console.enable", "id": 0}');
    this._registerDelegate('{"method": "Console.disable", "id": 0}');
    this._registerDelegate('{"method": "Console.clearConsoleMessages", "id": 0}');
    this._registerDelegate('{"method": "Console.setMonitoringXHREnabled", "params": {"enabled": {"optional": false, "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Console.addInspectedNode", "params": {"nodeId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "Network.enable", "id": 0}');
    this._registerDelegate('{"method": "Network.disable", "id": 0}');
    this._registerDelegate('{"method": "Network.setUserAgentOverride", "params": {"userAgent": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Network.setExtraHeaders", "params": {"headers": {"optional": false, "type": "object"}}, "id": 0}');
    this._registerDelegate('{"method": "Network.getResourceContent", "params": {"requestId": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Network.clearBrowserCache", "id": 0}');
    this._registerDelegate('{"method": "Network.clearBrowserCookies", "id": 0}');
    this._registerDelegate('{"method": "Network.setCacheDisabled", "params": {"cacheDisabled": {"optional": false, "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Database.enable", "id": 0}');
    this._registerDelegate('{"method": "Database.disable", "id": 0}');
    this._registerDelegate('{"method": "Database.getDatabaseTableNames", "params": {"databaseId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "Database.executeSQL", "params": {"databaseId": {"optional": false, "type": "number"},"query": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOMStorage.enable", "id": 0}');
    this._registerDelegate('{"method": "DOMStorage.disable", "id": 0}');
    this._registerDelegate('{"method": "DOMStorage.getDOMStorageEntries", "params": {"storageId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "DOMStorage.setDOMStorageItem", "params": {"storageId": {"optional": false, "type": "number"},"key": {"optional": false, "type": "string"},"value": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOMStorage.removeDOMStorageItem", "params": {"storageId": {"optional": false, "type": "number"},"key": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "ApplicationCache.getApplicationCaches", "id": 0}');
    this._registerDelegate('{"method": "DOM.getDocument", "id": 0}');
    this._registerDelegate('{"method": "DOM.requestChildNodes", "params": {"nodeId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.querySelector", "params": {"nodeId": {"optional": false, "type": "number"},"selector": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.querySelectorAll", "params": {"nodeId": {"optional": false, "type": "number"},"selector": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.setNodeName", "params": {"nodeId": {"optional": false, "type": "number"},"name": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.setNodeValue", "params": {"nodeId": {"optional": false, "type": "number"},"value": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.removeNode", "params": {"nodeId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.setAttributeValue", "params": {"nodeId": {"optional": false, "type": "number"},"name": {"optional": false, "type": "string"},"value": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.setAttributesText", "params": {"nodeId": {"optional": false, "type": "number"},"text": {"optional": false, "type": "string"},"name": {"optional": true , "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.removeAttribute", "params": {"nodeId": {"optional": false, "type": "number"},"name": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.getEventListenersForNode", "params": {"nodeId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.copyNode", "params": {"nodeId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.getOuterHTML", "params": {"nodeId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.setOuterHTML", "params": {"nodeId": {"optional": false, "type": "number"},"outerHTML": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.performSearch", "params": {"query": {"optional": false, "type": "string"},"runSynchronously": {"optional": true , "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.cancelSearch", "id": 0}');
    this._registerDelegate('{"method": "DOM.requestNode", "params": {"objectId": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.setInspectModeEnabled", "params": {"enabled": {"optional": false, "type": "boolean"},"highlightConfig": {"optional": true , "type": "object"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.highlightRect", "params": {"x": {"optional": false, "type": "number"},"y": {"optional": false, "type": "number"},"width": {"optional": false, "type": "number"},"height": {"optional": false, "type": "number"},"color": {"optional": true , "type": "object"},"outlineColor": {"optional": true , "type": "object"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.highlightNode", "params": {"nodeId": {"optional": false, "type": "number"},"highlightConfig": {"optional": false, "type": "object"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.hideHighlight", "id": 0}');
    this._registerDelegate('{"method": "DOM.highlightFrame", "params": {"frameId": {"optional": false, "type": "string"},"contentColor": {"optional": true , "type": "object"},"contentOutlineColor": {"optional": true , "type": "object"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.pushNodeByPathToFrontend", "params": {"path": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.resolveNode", "params": {"nodeId": {"optional": false, "type": "number"},"objectGroup": {"optional": true , "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.getAttributes", "params": {"nodeId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "DOM.moveTo", "params": {"nodeId": {"optional": false, "type": "number"},"targetNodeId": {"optional": false, "type": "number"},"anchorNodeId": {"optional": true , "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.getStylesForNode", "params": {"nodeId": {"optional": false, "type": "number"},"forcedPseudoClasses": {"optional": true , "type": "object"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.getComputedStyleForNode", "params": {"nodeId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.getInlineStyleForNode", "params": {"nodeId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.getAllStyleSheets", "id": 0}');
    this._registerDelegate('{"method": "CSS.getStyleSheet", "params": {"styleSheetId": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.getStyleSheetText", "params": {"styleSheetId": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.setStyleSheetText", "params": {"styleSheetId": {"optional": false, "type": "string"},"text": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.setPropertyText", "params": {"styleId": {"optional": false, "type": "object"},"propertyIndex": {"optional": false, "type": "number"},"text": {"optional": false, "type": "string"},"overwrite": {"optional": false, "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.toggleProperty", "params": {"styleId": {"optional": false, "type": "object"},"propertyIndex": {"optional": false, "type": "number"},"disable": {"optional": false, "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.setRuleSelector", "params": {"ruleId": {"optional": false, "type": "object"},"selector": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.addRule", "params": {"contextNodeId": {"optional": false, "type": "number"},"selector": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "CSS.getSupportedCSSProperties", "id": 0}');
    this._registerDelegate('{"method": "Timeline.start", "params": {"maxCallStackDepth": {"optional": true , "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "Timeline.stop", "id": 0}');
    this._registerDelegate('{"method": "Debugger.enable", "id": 0}');
    this._registerDelegate('{"method": "Debugger.disable", "id": 0}');
    this._registerDelegate('{"method": "Debugger.setBreakpointsActive", "params": {"active": {"optional": false, "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Debugger.setBreakpointByUrl", "params": {"lineNumber": {"optional": false, "type": "number"},"url": {"optional": true , "type": "string"},"urlRegex": {"optional": true , "type": "string"},"columnNumber": {"optional": true , "type": "number"},"condition": {"optional": true , "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Debugger.setBreakpoint", "params": {"location": {"optional": false, "type": "object"},"condition": {"optional": true , "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Debugger.removeBreakpoint", "params": {"breakpointId": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Debugger.continueToLocation", "params": {"location": {"optional": false, "type": "object"}}, "id": 0}');
    this._registerDelegate('{"method": "Debugger.stepOver", "id": 0}');
    this._registerDelegate('{"method": "Debugger.stepInto", "id": 0}');
    this._registerDelegate('{"method": "Debugger.stepOut", "id": 0}');
    this._registerDelegate('{"method": "Debugger.pause", "id": 0}');
    this._registerDelegate('{"method": "Debugger.resume", "id": 0}');
    this._registerDelegate('{"method": "Debugger.setScriptSource", "params": {"scriptId": {"optional": false, "type": "string"},"scriptSource": {"optional": false, "type": "string"},"preview": {"optional": true , "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Debugger.getScriptSource", "params": {"scriptId": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Debugger.setPauseOnExceptions", "params": {"state": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Debugger.evaluateOnCallFrame", "params": {"callFrameId": {"optional": false, "type": "string"},"expression": {"optional": false, "type": "string"},"objectGroup": {"optional": true , "type": "string"},"includeCommandLineAPI": {"optional": true , "type": "boolean"},"returnByValue": {"optional": true , "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "DOMDebugger.setDOMBreakpoint", "params": {"nodeId": {"optional": false, "type": "number"},"type": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOMDebugger.removeDOMBreakpoint", "params": {"nodeId": {"optional": false, "type": "number"},"type": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOMDebugger.setEventListenerBreakpoint", "params": {"eventName": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOMDebugger.removeEventListenerBreakpoint", "params": {"eventName": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOMDebugger.setXHRBreakpoint", "params": {"url": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "DOMDebugger.removeXHRBreakpoint", "params": {"url": {"optional": false, "type": "string"}}, "id": 0}');
    this._registerDelegate('{"method": "Profiler.enable", "id": 0}');
    this._registerDelegate('{"method": "Profiler.disable", "id": 0}');
    this._registerDelegate('{"method": "Profiler.isEnabled", "id": 0}');
    this._registerDelegate('{"method": "Profiler.start", "id": 0}');
    this._registerDelegate('{"method": "Profiler.stop", "id": 0}');
    this._registerDelegate('{"method": "Profiler.getProfileHeaders", "id": 0}');
    this._registerDelegate('{"method": "Profiler.getProfile", "params": {"type": {"optional": false, "type": "string"},"uid": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "Profiler.removeProfile", "params": {"type": {"optional": false, "type": "string"},"uid": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "Profiler.clearProfiles", "id": 0}');
    this._registerDelegate('{"method": "Profiler.takeHeapSnapshot", "id": 0}');
    this._registerDelegate('{"method": "Profiler.collectGarbage", "id": 0}');
    this._registerDelegate('{"method": "Worker.setWorkerInspectionEnabled", "params": {"value": {"optional": false, "type": "boolean"}}, "id": 0}');
    this._registerDelegate('{"method": "Worker.sendMessageToWorker", "params": {"workerId": {"optional": false, "type": "number"},"message": {"optional": false, "type": "object"}}, "id": 0}');
    this._registerDelegate('{"method": "Worker.connectToWorker", "params": {"workerId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "Worker.disconnectFromWorker", "params": {"workerId": {"optional": false, "type": "number"}}, "id": 0}');
    this._registerDelegate('{"method": "Worker.setAutoconnectToWorkers", "params": {"value": {"optional": false, "type": "boolean"}}, "id": 0}');
    this._eventArgs["Inspector.frontendReused"] = [];
    this._eventArgs["Inspector.bringToFront"] = [];
    this._eventArgs["Inspector.disconnectFromBackend"] = [];
    this._eventArgs["Inspector.reset"] = [];
    this._eventArgs["Inspector.showPanel"] = ["panel"];
    this._eventArgs["Inspector.startUserInitiatedDebugging"] = [];
    this._eventArgs["Inspector.evaluateForTestInFrontend"] = ["testCallId","script"];
    this._eventArgs["Inspector.inspect"] = ["object","hints"];
    this._eventArgs["Inspector.didCreateWorker"] = ["id","url","isShared"];
    this._eventArgs["Inspector.didDestroyWorker"] = ["id"];
    this._eventArgs["Page.domContentEventFired"] = ["timestamp"];
    this._eventArgs["Page.loadEventFired"] = ["timestamp"];
    this._eventArgs["Page.frameNavigated"] = ["frame","loaderId"];
    this._eventArgs["Page.frameDetached"] = ["frameId"];
    this._eventArgs["Console.messageAdded"] = ["messageObj"];
    this._eventArgs["Console.messageRepeatCountUpdated"] = ["count"];
    this._eventArgs["Console.messagesCleared"] = [];
    this._eventArgs["Network.requestWillBeSent"] = ["requestId","frameId","loaderId","documentURL","request","timestamp","initiator","stackTrace","redirectResponse"];
    this._eventArgs["Network.resourceMarkedAsCached"] = ["requestId"];
    this._eventArgs["Network.responseReceived"] = ["requestId","timestamp","type","response"];
    this._eventArgs["Network.dataReceived"] = ["requestId","timestamp","dataLength","encodedDataLength"];
    this._eventArgs["Network.loadingFinished"] = ["requestId","timestamp"];
    this._eventArgs["Network.loadingFailed"] = ["requestId","timestamp","errorText","canceled"];
    this._eventArgs["Network.resourceLoadedFromMemoryCache"] = ["requestId","frameId","loaderId","documentURL","timestamp","initiator","resource"];
    this._eventArgs["Network.webSocketWillSendHandshakeRequest"] = ["requestId","timestamp","request"];
    this._eventArgs["Network.webSocketHandshakeResponseReceived"] = ["requestId","timestamp","response"];
    this._eventArgs["Network.webSocketCreated"] = ["requestId","url"];
    this._eventArgs["Network.webSocketClosed"] = ["requestId","timestamp"];
    this._eventArgs["Database.addDatabase"] = ["database"];
    this._eventArgs["Database.sqlTransactionSucceeded"] = ["transactionId","columnNames","values"];
    this._eventArgs["Database.sqlTransactionFailed"] = ["transactionId","sqlError"];
    this._eventArgs["DOMStorage.addDOMStorage"] = ["storage"];
    this._eventArgs["DOMStorage.updateDOMStorage"] = ["storageId"];
    this._eventArgs["ApplicationCache.updateApplicationCacheStatus"] = ["status"];
    this._eventArgs["ApplicationCache.updateNetworkState"] = ["isNowOnline"];
    this._eventArgs["DOM.documentUpdated"] = [];
    this._eventArgs["DOM.setChildNodes"] = ["parentId","nodes"];
    this._eventArgs["DOM.attributesUpdated"] = ["nodeId"];
    this._eventArgs["DOM.inlineStyleInvalidated"] = ["nodeIds"];
    this._eventArgs["DOM.characterDataModified"] = ["nodeId","newValue"];
    this._eventArgs["DOM.childNodeCountUpdated"] = ["nodeId","newValue"];
    this._eventArgs["DOM.childNodeInserted"] = ["parentNodeId","previousNodeId","node"];
    this._eventArgs["DOM.childNodeRemoved"] = ["parentNodeId","nodeId"];
    this._eventArgs["DOM.searchResults"] = ["nodeIds"];
    this._eventArgs["Timeline.started"] = [];
    this._eventArgs["Timeline.stopped"] = [];
    this._eventArgs["Timeline.eventRecorded"] = ["record"];
    this._eventArgs["Debugger.debuggerWasEnabled"] = [];
    this._eventArgs["Debugger.debuggerWasDisabled"] = [];
    this._eventArgs["Debugger.scriptParsed"] = ["scriptId","url","startLine","startColumn","endLine","endColumn","isContentScript"];
    this._eventArgs["Debugger.scriptFailedToParse"] = ["url","data","firstLine","errorLine","errorMessage"];
    this._eventArgs["Debugger.breakpointResolved"] = ["breakpointId","location"];
    this._eventArgs["Debugger.paused"] = ["details"];
    this._eventArgs["Debugger.resumed"] = [];
    this._eventArgs["Profiler.profilerWasEnabled"] = [];
    this._eventArgs["Profiler.profilerWasDisabled"] = [];
    this._eventArgs["Profiler.addProfileHeader"] = ["header"];
    this._eventArgs["Profiler.addHeapSnapshotChunk"] = ["uid","chunk"];
    this._eventArgs["Profiler.finishHeapSnapshot"] = ["uid"];
    this._eventArgs["Profiler.setRecordingProfile"] = ["isProfiling"];
    this._eventArgs["Profiler.resetProfiles"] = [];
    this._eventArgs["Profiler.reportHeapSnapshotProgress"] = ["done","total"];
    this._eventArgs["Worker.workerCreated"] = ["workerId","url","inspectorConnected"];
    this._eventArgs["Worker.workerTerminated"] = ["workerId"];
    this._eventArgs["Worker.dispatchMessageFromWorker"] = ["workerId","message"];
    this.registerInspectorDispatcher = this._registerDomainDispatcher.bind(this, "Inspector");
    this.registerPageDispatcher = this._registerDomainDispatcher.bind(this, "Page");
    this.registerConsoleDispatcher = this._registerDomainDispatcher.bind(this, "Console");
    this.registerNetworkDispatcher = this._registerDomainDispatcher.bind(this, "Network");
    this.registerDatabaseDispatcher = this._registerDomainDispatcher.bind(this, "Database");
    this.registerDOMStorageDispatcher = this._registerDomainDispatcher.bind(this, "DOMStorage");
    this.registerApplicationCacheDispatcher = this._registerDomainDispatcher.bind(this, "ApplicationCache");
    this.registerDOMDispatcher = this._registerDomainDispatcher.bind(this, "DOM");
    this.registerTimelineDispatcher = this._registerDomainDispatcher.bind(this, "Timeline");
    this.registerDebuggerDispatcher = this._registerDomainDispatcher.bind(this, "Debugger");
    this.registerProfilerDispatcher = this._registerDomainDispatcher.bind(this, "Profiler");
    this.registerWorkerDispatcher = this._registerDomainDispatcher.bind(this, "Worker");
}

InspectorBackendStub.prototype = {
    _wrap: function(callback)
    {
        var callbackId = this._lastCallbackId++;
        this._callbacks[callbackId] = callback || function() {};
        return callbackId;
    },

    _registerDelegate: function(requestString)
    {
        var domainAndFunction = JSON.parse(requestString).method.split(".");
        var agentName = domainAndFunction[0] + "Agent";
        if (!window[agentName])
            window[agentName] = {};
        window[agentName][domainAndFunction[1]] = this._sendMessageToBackend.bind(this, requestString);
        window[agentName][domainAndFunction[1]]["invoke"] = this._invoke.bind(this, requestString)
    },

    _invoke: function(requestString, args, callback)
    {
        var request = JSON.parse(requestString);
        request.params = args;
        this._wrapCallbackAndSendMessageObject(request, callback);
    },

    _sendMessageToBackend: function()
    {
        var args = Array.prototype.slice.call(arguments);
        var request = JSON.parse(args.shift());
        var callback = (args.length && typeof args[args.length - 1] === "function") ? args.pop() : 0;
        var domainAndMethod = request.method.split(".");
        var agentMethod = domainAndMethod[0] + "Agent." + domainAndMethod[1];

        var hasParams = false;
        if (request.params) {
            for (var key in request.params) {
                var typeName = request.params[key].type;
                var optionalFlag = request.params[key].optional;

                if (args.length === 0 && !optionalFlag) {
                    console.error("Protocol Error: Invalid number of arguments for method '" + agentMethod + "' call. It must have the next arguments '" + JSON.stringify(request.params) + "'.");
                    return;
                }

                var value = args.shift();
                if (optionalFlag && typeof value === "undefined") {
                    delete request.params[key];
                    continue;
                }

                if (typeof value !== typeName) {
                    console.error("Protocol Error: Invalid type of argument '" + key + "' for method '" + agentMethod + "' call. It must be '" + typeName + "' but it is '" + typeof value + "'.");
                    return;
                }

                request.params[key] = value;
                hasParams = true;
            }
            if (!hasParams)
                delete request.params;
        }

        if (args.length === 1 && !callback) {
            if (typeof args[0] !== "undefined") {
                console.error("Protocol Error: Optional callback argument for method '" + agentMethod + "' call must be a function but its type is '" + typeof args[0] + "'.");
                return;
            }
        }

        this._wrapCallbackAndSendMessageObject(request, callback);
    },

    _wrapCallbackAndSendMessageObject: function(messageObject, callback)
    {
        messageObject.id = this._wrap(callback || function() {});

        if (window.dumpInspectorProtocolMessages)
            console.log("frontend: " + JSON.stringify(messageObject));

        ++this._pendingResponsesCount;
        this.sendMessageObjectToBackend(messageObject);
    },

    sendMessageObjectToBackend: function(messageObject)
    {
        var message = JSON.stringify(messageObject);
        InspectorFrontendHost.sendMessageToBackend(message);
    },

    _registerDomainDispatcher: function(domain, dispatcher)
    {
        this._domainDispatchers[domain] = dispatcher;
    },

    dispatch: function(message)
    {
        if (window.dumpInspectorProtocolMessages)
            console.log("backend: " + ((typeof message === "string") ? message : JSON.stringify(message)));

        var messageObject = (typeof message === "string") ? JSON.parse(message) : message;

        if ("id" in messageObject) { // just a response for some request
            if (messageObject.error) {
                messageObject.error.__proto__ = {
                    getDescription: function()
                    {
                        switch(this.code) {
                            case -32700: return "Parse error";
                            case -32600: return "Invalid Request";
                            case -32601: return "Method not found";
                            case -32602: return "Invalid params";
                            case -32603: return "Internal error";;
                            case -32000: return "Server error";
                        }
                    },

                    toString: function()
                    {
                        var description ="Unknown error code";
                        return this.getDescription() + "(" + this.code + "): " + this.message + "." + (this.data ? " " + this.data.join(" ") : "");
                    },

                    getMessage: function()
                    {
                        return this.message;
                    }
                }

                if (messageObject.error.code !== -32000)
                    this.reportProtocolError(messageObject);
            }

            var arguments = [];
            if (messageObject.result) {
                for (var key in messageObject.result)
                    arguments.push(messageObject.result[key]);
            }

            var callback = this._callbacks[messageObject.id];
            if (callback) {
                arguments.unshift(messageObject.error);
                callback.apply(null, arguments);
                --this._pendingResponsesCount;
                delete this._callbacks[messageObject.id];
            }

            if (this._scripts && !this._pendingResponsesCount)
                this.runAfterPendingDispatches();

            return;
        } else {
            var method = messageObject.method.split(".");
            var domainName = method[0];
            var functionName = method[1];
            if (!(domainName in this._domainDispatchers)) {
                console.error("Protocol Error: the message is for non-existing domain '" + domainName + "'");
                return;
            }
            var dispatcher = this._domainDispatchers[domainName];
            if (!(functionName in dispatcher)) {
                console.error("Protocol Error: Attempted to dispatch an unimplemented method '" + messageObject.method + "'");
                return;
            }

            if (!this._eventArgs[messageObject.method]) {
                console.error("Protocol Error: Attempted to dispatch an unspecified method '" + messageObject.method + "'");
                return;
            }

            var params = [];
            if (messageObject.params) {
                var paramNames = this._eventArgs[messageObject.method];
                for (var i = 0; i < paramNames.length; ++i)
                    params.push(messageObject.params[paramNames[i]]);
            }

            dispatcher[functionName].apply(dispatcher, params);
        }
    },

    reportProtocolError: function(messageObject)
    {
        console.error("Request with id = " + messageObject.id + " failed. " + messageObject.error);
    },

    runAfterPendingDispatches: function(script)
    {
        if (!this._scripts)
            this._scripts = [];

        if (script)
            this._scripts.push(script);

        if (!this._pendingResponsesCount) {
            var scripts = this._scripts;
            this._scripts = []
            for (var id = 0; id < scripts.length; ++id)
                 scripts[id].call(this);
        }
    }
}

InspectorBackend = new InspectorBackendStub();