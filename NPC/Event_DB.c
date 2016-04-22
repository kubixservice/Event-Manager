-	script	Event_Database	-1,{
OnSetEvent:
	$EVT_Count = 0;
	sleep 5000;
	// Event Name, Enable EVENT, Disable EVENT, Prize ID, Prize Amount, Max Players, Map Name, Map X, Map Y, EventID, Minimum Players
	// Prize ID 1 = Event Points.
	AddEvent( "RFYL", "RFYL_Event::OnEnableEvent", "RFYL_Event::OnDisableEvent", 7539, 3, 50, "rfyl", 32, 28, 1, 2 );
	AddEvent( "Kaboom", "BOMB_Event::OnEnableEvent", "BOMB_Event::OnDisableEvent", 7539, 3, 50, "bomb", 32, 28, 2, 2 );
	EM_DebugMode( $EVT_Count, 1);
	end;
}