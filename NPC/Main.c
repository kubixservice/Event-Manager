/*
	Event Manager 3.0
	By Kubix
	23.04.2016
*/

function	script	phpCollect	{
	query_sql( "UPDATE current_event SET event = '" + getarg(0) + "' WHERE id = '1'" );
	return;
}

-	script	EventManagerMain	FAKE_NPC,{
OnInit:
	donpcevent "Event_Database::OnSetEvent";
	bindatcmd "joinevent", strnpcinfo(0) + "::OnJoinEvent", 0, 99;
	bindatcmd "leaveevent", strnpcinfo(0) + "::OnLeaveEvent", 0, 99;
	bindatcmd "startevent", strnpcinfo(0) + "::OnStartEvent", 99, 99;
	bindatcmd "checkevent", strnpcinfo(0) + "::OnCheckEvent", 99, 99;
	// = @event
	bindatcmd "event", strnpcinfo(0) + "::OnMyPoints", 0, 99;	
	// ======== Event settings:
	$@RFYL_MOBID = 3674; // Mob ID for RFYL event
	$@BOMB_MOBID = BOMBPORING; // Mob ID for Bomb Poring Event
	$@EVT_SETTINGS$ = strnpcinfo(0) + "::OnSetting"; // Settings NPC ( don't change )
	$@MainMap$ = "ironbridge"; // Main Map
	$@MainX = 120; // Main X coordinate
	$@MainY = 105; // Main Y coordinate
	$@Event_Flood = 120; // Announce flood time limit
	
OnSetting:
	// = New queue
	if( $@EVT_QUEUE )
		queuedel( $@EVT_QUEUE );
	
	$@EVT_QUEUE = queue();
	$Event_Status = false;
	deletearray $@EVT_ARRAY[0], getarraysize( $@EVT_ARRAY );
	phpCollect( "No Event" );
	end;

OnMyPoints:
	message strcharinfo(0), "Event points: " + #EVENTPOINTS;
	for( .@i = 0; .@i < getarraysize( Event_Win_IDs ); .@i ++ )
	{
		if( Event_Win_IDs[ .@i ] != 0 )
		{
			getitem return_Event_Prize( Event_Win_IDs[.@i] ), return_Event_Amount( Event_Win_IDs[.@i] );
			deletearray Event_Win_IDs[.@i], 1;
		}
	}
	end;
	
OnJoinEvent:
	if( !$Event_Status || !$Event )
	{
		message strcharinfo(0), "No event to register.";
		end;
	}
	
	if( checkmount() )
	{
		message strcharinfo(0), "Leave your mount outside! No riding mounts on the floor here!";
		end;
	}
	
	if( queuesize( $@EVT_QUEUE ) >= return_MaxPlayers( $Event ) )
	{
		message strcharinfo(0), "Maximum players already registered!";
		end;
	}
	
	if( !queueadd( $@EVT_QUEUE, get_unique_id() ) )
	{
		message strcharinfo(0), "You already in queue!";
		end;
	}
	$@EVT_ARRAY[$@EVT_PLAYERS] = getcharid(0);
	$@EVT_PLAYERS ++;
	message strcharinfo(0), "Successfully registered.";
	end;

OnLeaveEvent:
	if( !queueremove( $@EVT_QUEUE, get_unique_id() ) )
	{
		message strcharinfo(0), "You are not in queue.";
		end;
	}
	
	for( .@a = 0; .@a < getarraysize( $@EVT_ARRAY ); .@a ++ )
	{
		if( $@EVT_ARRAY[ .@a ] == getcharid(0) )
		{
			deletearray $@EVT_ARRAY[ .@a ], 1;
			$@EVT_PLAYERS --;
		}
	}
		
	message strcharinfo(0), "Successfully leaved.";
	end;	

OnStartEvent:
	if ( .@atcmd_parameters$[0] == "" ) {
		message strcharinfo(0), "@startevent failed: Input event name";
		end;
	}

	if ( return_Event_ID( .@atcmd_parameters$[0] ) < 1 ) 
	{
		message strcharinfo(0), "@startevent failed: Incorrect Event Name/EventID";
		end;
	}
	
	if ( return_Enable_NPC( return_Event_ID( .@atcmd_parameters$[0] ) ) == "" ) 
	{
		message strcharinfo(0), "@startevent failed: Can't find 'Enable Event Label'.";
		end;
	}
	message strcharinfo(0), "Event started. ID : " + return_Event_ID( .@atcmd_parameters$[0] );
	
	// == Start the event:
	phpCollect( .@atcmd_parameters$[0] );
	$Event = return_Event_ID( .@atcmd_parameters$[0] );
	doevent return_Enable_NPC( $Event );
	statusmes "Event " + .@atcmd_parameters$[0] + ", ID " + return_Event_ID( .@atcmd_parameters$[0] ) + " successfully started.";
	end;

OnCheckEvent:
	.id = return_Event_ID( .@atcmd_parameters$[0] );
	dispbottom "Name: " + return_Event_Name( .id );
	dispbottom "Map: " + return_Event_Map( .id );
	dispbottom "X: " + return_Event_X( .id );
	dispbottom "Y: " + return_Event_Y( .id );
	dispbottom "ID: " + return_Event_Prize( .id );
	dispbottom "Amount: " + return_Event_Amount( .id );
	dispbottom "Enable: " + return_Enable_NPC( .id );
	dispbottom "Disable: " + return_Disable_NPC( .id );
	dispbottom "Desc: " + return_Event_DescName( .id );
	dispbottom "Max: " + return_MaxPlayers( .id );
	dispbottom "Min: " + return_MinPlayers( .id );
	end;
	
OnClock1000:
OnClock1200:
	if( $Event_Status == true )
		donpcevent $@EVT_SETTINGS$;
	
	$Event = return_Event_ID( "RFYL" );
	donpcevent return_Enable_NPC( $Event );
	phpCollect( return_Event_Name( $Event ) );
end;

OnPCLoadMapEvent:
	if( strcharinfo(3) == return_Event_Map( $Event ) ) 
	{
		if( !checkmount() )
			end;
		else
		{
			message strcharinfo(0), "You have 10 seconds to leave your mount.";
			sleep2 10000;
			if( !checkmount() )
				end;
			message strcharinfo(0), "You has been kicked from event.";
		}
	}
OnPCLogoutEvent:
OnPCDieEvent:
	if( !queueremove( $@EVT_QUEUE, get_unique_id() ) || $Event_Status == false || strcharinfo(3) != return_Event_Map( $Event ) )
		end;
	
	for( .@a = 0; .@a < getarraysize( $@EVT_ARRAY ); .@a ++ )
	{
		if( $@EVT_ARRAY[ .@a ] == getcharid(0) )
		{
			deletearray $@EVT_ARRAY[ .@a ], 1;
			$@EVT_PLAYERS --;
		}
	}
	if( countitem( 1051 ) )
		delitem 1051, countitem( 1051 );
	
	warp "SavePoint", 0, 0;
	sleep2 1000;
	recovery;
	end;
}