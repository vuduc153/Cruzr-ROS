
(cl:in-package :asdf)

(defsystem "rosapi-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :rosapi-msg
)
  :components ((:file "_package")
    (:file "GetParamNames" :depends-on ("_package_GetParamNames"))
    (:file "_package_GetParamNames" :depends-on ("_package"))
    (:file "ServiceNode" :depends-on ("_package_ServiceNode"))
    (:file "_package_ServiceNode" :depends-on ("_package"))
    (:file "GetTime" :depends-on ("_package_GetTime"))
    (:file "_package_GetTime" :depends-on ("_package"))
    (:file "TopicType" :depends-on ("_package_TopicType"))
    (:file "_package_TopicType" :depends-on ("_package"))
    (:file "ServicesForType" :depends-on ("_package_ServicesForType"))
    (:file "_package_ServicesForType" :depends-on ("_package"))
    (:file "MessageDetails" :depends-on ("_package_MessageDetails"))
    (:file "_package_MessageDetails" :depends-on ("_package"))
    (:file "SearchParam" :depends-on ("_package_SearchParam"))
    (:file "_package_SearchParam" :depends-on ("_package"))
    (:file "Publishers" :depends-on ("_package_Publishers"))
    (:file "_package_Publishers" :depends-on ("_package"))
    (:file "TopicsForType" :depends-on ("_package_TopicsForType"))
    (:file "_package_TopicsForType" :depends-on ("_package"))
    (:file "ServiceHost" :depends-on ("_package_ServiceHost"))
    (:file "_package_ServiceHost" :depends-on ("_package"))
    (:file "Services" :depends-on ("_package_Services"))
    (:file "_package_Services" :depends-on ("_package"))
    (:file "ServiceRequestDetails" :depends-on ("_package_ServiceRequestDetails"))
    (:file "_package_ServiceRequestDetails" :depends-on ("_package"))
    (:file "NodeDetails" :depends-on ("_package_NodeDetails"))
    (:file "_package_NodeDetails" :depends-on ("_package"))
    (:file "Nodes" :depends-on ("_package_Nodes"))
    (:file "_package_Nodes" :depends-on ("_package"))
    (:file "SetParam" :depends-on ("_package_SetParam"))
    (:file "_package_SetParam" :depends-on ("_package"))
    (:file "GetParam" :depends-on ("_package_GetParam"))
    (:file "_package_GetParam" :depends-on ("_package"))
    (:file "DeleteParam" :depends-on ("_package_DeleteParam"))
    (:file "_package_DeleteParam" :depends-on ("_package"))
    (:file "Topics" :depends-on ("_package_Topics"))
    (:file "_package_Topics" :depends-on ("_package"))
    (:file "HasParam" :depends-on ("_package_HasParam"))
    (:file "_package_HasParam" :depends-on ("_package"))
    (:file "GetActionServers" :depends-on ("_package_GetActionServers"))
    (:file "_package_GetActionServers" :depends-on ("_package"))
    (:file "Subscribers" :depends-on ("_package_Subscribers"))
    (:file "_package_Subscribers" :depends-on ("_package"))
    (:file "ServiceResponseDetails" :depends-on ("_package_ServiceResponseDetails"))
    (:file "_package_ServiceResponseDetails" :depends-on ("_package"))
    (:file "ServiceType" :depends-on ("_package_ServiceType"))
    (:file "_package_ServiceType" :depends-on ("_package"))
    (:file "ServiceProviders" :depends-on ("_package_ServiceProviders"))
    (:file "_package_ServiceProviders" :depends-on ("_package"))
  ))