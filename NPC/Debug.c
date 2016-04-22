function	script	EM_DebugMode	{

	switch ( getarg(1) ) {
		case 1:
			statusmes( sprintf( "Done loading %d event's.", getarg(0) ) );
			return;
		default: return;
	}
}