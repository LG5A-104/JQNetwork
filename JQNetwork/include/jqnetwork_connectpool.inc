﻿/*
    This file is part of JQNetwork
    
    Library introduce: https://github.com/188080501/JQNetwork

    Copyright: Jason

    Contact email: Jason@JasonServer.com
    
    GitHub: https://github.com/188080501/
*/

#ifndef JQNETWORK_INCLUDE_JQNETWORK_CONNECTPOOL_INC
#define JQNETWORK_INCLUDE_JQNETWORK_CONNECTPOOL_INC

// JQNetwork lib import
#include "jqnetwork_connectpool.h"

inline bool JQNetworkConnectPool::containsConnect(const QString &hostName, const quint16 &port)
{
    mutex_.lock();

    auto contains = bimapForHostAndPort1.contains( QString( "%1:%2" ).arg( hostName ).arg( port ) );

    mutex_.unlock();

    return contains;
}

inline bool JQNetworkConnectPool::containsConnect(const qintptr &socketDescriptor)
{
    mutex_.lock();

    auto contains = bimapForSocketDescriptor1.contains( socketDescriptor );

    mutex_.unlock();

    return contains;
}

inline void JQNetworkConnectPool::onConnectToHostError(const JQNetworkConnectPointer &connect)
{
    NULLPTR_CHECK( connectPoolSettings_->connectToHostErrorCallback );
    connectPoolSettings_->connectToHostErrorCallback( connect );
}

inline void JQNetworkConnectPool::onConnectToHostTimeout(const JQNetworkConnectPointer &connect)
{
    NULLPTR_CHECK( connectPoolSettings_->connectToHostTimeoutCallback );
    connectPoolSettings_->connectToHostTimeoutCallback( connect );
}

inline void JQNetworkConnectPool::onRemoteHostClosed(const JQNetworkConnectPointer &connect)
{
    NULLPTR_CHECK( connectPoolSettings_->remoteHostClosedCallback );
    connectPoolSettings_->remoteHostClosedCallback( connect );
}

inline void JQNetworkConnectPool::onPackageReceived(const JQNetworkConnectPointer &connect, const JQNetworkPackageSharedPointer &package)
{
    NULLPTR_CHECK( connectPoolSettings_->packageReceivedCallback );
    connectPoolSettings_->packageReceivedCallback( connect, package );
}

#endif//JQNETWORK_INCLUDE_JQNETWORK_CONNECTPOOL_INC