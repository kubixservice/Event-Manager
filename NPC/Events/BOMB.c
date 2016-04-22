-	script	BOMB_Event	FAKE_NPC,{
OnEnableEvent:
	$Event_Status = true;
	
	while( true )
	{
		.Players = ( return_MinPlayers( $Event ) - queuesize( $@EVT_QUEUE ) );
		if( .Players <= 0 || !$Event_Status )
			break;
		
		if( $Event_Flood < gettimetick(2) )
		{
			announce "[Event Manager]: Event --- " + return_Event_DescName( $Event ) + " --- ( " + .Players + " ) more players to start.", bc_all, C_AQUA, FW_BOLD, 16;
			$Event_Flood = gettimetick(2) + $@Event_Flood;
		}
		sleep 20000;
	}
	if( !$Event_Status )
		end;
	
	announce "[Event Manager]: Event --- " + return_Event_DescName( $Event ) + " --- ( " + .Players + " ) will start in 2 minutes!", bc_all, C_AQUA, FW_BOLD, 16;
	initnpctimer;
	end;
	
OnTimer60000:
	announce "[Event Manager]: Event --- " + return_Event_DescName( $Event ) + " --- will start in 1 minute!", bc_all, C_AQUA, FW_BOLD, 16;
OnTimer120000:
	stopnpctimer;
	donpcevent strnpcinfo(0) + "::OnStart";
	end;

OnStart:
	announce "[Event Manager]: Event --- " + return_Event_DescName( $Event ) + " --- started! Good luck.", bc_all, C_AQUA, FW_BOLD, 16;
	$Event_Status = true; // started.	
	freeloop( 1 );
	for( .i = 0; .i < getarraysize( $@EVT_ARRAY ); .i ++ )
	{
		if( $@EVT_ARRAY[ .i ] == 0 )
		{
			.Leaver ++;
			if( $@EVT_PLAYERS > getarraysize( $@EVT_ARRAY ) )
				$@EVT_PLAYERS --;
		}
		
		warpchar return_Event_Map( $Event ), return_Event_X( $Event ), return_Event_Y( $Event ), $@EVT_ARRAY[ .i ];
		sleep 20;
	}
	freeloop( 0 );
	sleep 5000;
	mapannounce return_Event_Map( $Event ), "[Event Manager]: The Monster will spawn in 30 seconds!", bc_map, C_AQUA, FW_BOLD, 16;
	sleep 30000;
	mapannounce return_Event_Map( $Event ), "[Event Manager]: All monsters spawned! Good Luck!", bc_map, C_AQUA, FW_BOLD, 16;
	
	while( true )
	{
		if( queuesize( $@EVT_QUEUE ) == 1 )
		{
			for( .i = 0; .i < getarraysize( $@EVT_ARRAY ); .i ++ )
				if( $@EVT_ARRAY[ .i ] == 0 )
					break;
				
			Event_Winner( $@EVT_ARRAY[0], $Event );
			donpcevent return_Disable_NPC( $Event );
			end;
		}
		else if( queuesize( $@EVT_QUEUE ) == 0 )
			break;
		
		.@more += rand( 1, 2 );

		monster return_Event_Map( $Event ), 0,0, "Come On Baby!!!", $@BOMB_MOBID, 2 + .@more, "", 0;
		monster return_Event_Map( $Event ), 0,0, "Come On Baby!!!", $@BOMB_MOBID, 2 + .@more, "", 1;
		monster return_Event_Map( $Event ), 0,0, "Come On Baby!!!", $@BOMB_MOBID, 2 + .@more, "", 2;
		sleep 5000;
	}
	announce "[Event Manager]: Event --- " + return_Event_DescName( $Event ) + " --- ended! There are no winners at this time!", bc_all, C_AQUA, FW_BOLD, 16;
	donpcevent return_Disable_NPC( $Event );
	end;
	
OnDisableEvent:
	mapwarp return_Event_Map( $Event ), $@MainMap$, $@MainX, $@MainY;
	killmonsterall return_Event_Map( $Event );
	$Event = .Leaver = false;
	donpcevent $@EVT_SETTINGS$;
	end;
}