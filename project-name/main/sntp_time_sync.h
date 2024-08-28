/////////////////////////////////////////////////////////////////////////////

///	Purpose: SNTP Configuration Header

/// Author: Nubal Manhas

/////////////////////////////////////////////////////////////////////////////

/*
    Starts the NTP server synchronization task
*/
void sntp_time_sync_task_start(void);

/*
    Returns local time if set
    return = local time buffer
*/
char* sntp_time_sync_get_time(void);

