/*
 * Copyright (C) 2015   Jeremy Chen jeremy_cz@yahoo.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <vector>
#include <common_base/CBaseNameProxy.h>
#include <common_base/CFdbMessage.h>
#include <utils/CNsConfig.h>

CBaseNameProxy::CBaseNameProxy()
    : CBaseClient("NameServer")
{}

void CBaseNameProxy::subscribeListener(NFdbBase::FdbNsMsgCode code, const char *svc_name)
{
    CFdbMsgSubscribeList subscribe_list;
    addNotifyItem(subscribe_list, code, svc_name);
    subscribe(subscribe_list);
}

void CBaseNameProxy::unsubscribeListener(NFdbBase::FdbNsMsgCode code, const char *svc_name)
{
    CFdbMsgSubscribeList subscribe_list;
    addNotifyItem(subscribe_list, code, svc_name);
    unsubscribe(subscribe_list);
}

void CBaseNameProxy::replaceSourceUrl(NFdbBase::FdbMsgAddressList &msg_addr_list, CFdbSession *session)
{
    auto &addr_list = msg_addr_list.address_list();
    for (auto it = addr_list.vpool().begin(); it != addr_list.vpool().end(); ++it)
    {
        replaceUrlIpAddress(*it, session);
    }
}

