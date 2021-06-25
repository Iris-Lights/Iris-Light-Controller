/**
 * @file messagemanager.cpp
 * 
 * @brief Contains definitions of funcitons from messagemanager.h
 * @version 0.1
 * @date 2021-06-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "messagemanager.h"
#include "messageretriever.h"

using Msg = MessageRetrieverBase::Message; 

Msg * MessageManager::getNewMessage(){

    // scan through sources. if there is a new message, then get that new message. 
    for( unsigned int i = source_index; i < num_sources + source_index; ++i ){
        if(message_sources[i % num_sources]->isMessageAvailable()){
           source_index = (i + 1) % num_sources;
           return message_sources[i % num_sources]->getNewMessage();
        }

        return nullptr; 
    }
}