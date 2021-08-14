/**
 * @file messagesystem.cpp
 * 
 * @brief File containing information regaurding the message system implmenentaiton
 * @version 0.1
 * @date 2021-08-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "messagesystem.h"
#include "messagemanager.h"
#include "thread.h"
#include "utils.h"

bool MessageSystem::startMessageSystem(MessageSystem::messageSystemConfig *config)
{
    Thread::thread_config threadconfig{};
    threadconfig.task = getTaskEntry(_run);
    MessageSystem::MessageThreadHandle = Thread::create_thread(&threadconfig);
}

bool MessageSystem::killMessageSystem()
{
    Thread::delete_task(&MessageSystem::MessageThreadHandle);
    return true;
}

void MessageSystem::_run(task_param_requirements)
{
    MessageManager manager; // The funnel for messages from the different message sources

    while (true)
    {

        Message *msg = manager.getNewMessage();
        
        // If there is not a new message, then allow this to sleep for a while.
        if (Utils::is_nullptr(msg))
        {   
            // Delay the message task for 10 ticks
            delayTask(100 / (double)tickLength);
        }
    }
}