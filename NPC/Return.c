/**************
 * Return: Event Name
 * getarg(0)	-> EventID
 * 
 * This function will return Event Name based on EventID
 * Use: return_Event_Name( $Event );
 **************/
function	script	return_Event_Name	{
	if (!getarg(0)) return "None";
	return getd("$event_name_" + getarg(0) + "$");
}

/**************
 * Return: Event ID
 * getarg(0)	-> Event Name
 * 
 * This function will return Event ID based on Event Name
 * Use: return_Event_ID( "EventName" );
 **************/
function	script	return_Event_ID	{
	if (getarg(0) == "" || getarg(0) == "None") return 0;
	return getd("$event_" + getarg(0));
}

/**************
 * Return: Event Map
 * getarg(0)	-> EventID
 * 
 * This function will return Event Map based on Event ID
 * Use: return_Event_Name( $Event );
 **************/
function	script	return_Event_Map	{
	if (getarg(0) < 0) return "";
	return getd("$event_map_name_" + getarg(0) + "$");
}

/**************
 * Return: Event X coordinate
 * getarg(0)	-> EventID
 * 
 * This function will return Event X coordinate based on Event ID
 * Use: return_Event_X( $Event );
 **************/
function	script	return_Event_X	{
	if (getarg(0) < 0) return 0;
	return getd("$event_map_x_" + getarg(0));
}

/**************
 * Return: Event Y coordinate
 * getarg(0)	-> EventID
 * 
 * This function will return Event Y coordinate based on Event ID
 * Use: return_Event_Y( $Event );
 **************/
function	script	return_Event_Y	{
	if (getarg(0) < 0) return 0;
	return getd("$event_map_y_" + getarg(0));
}

/**************
 * Return: Event prize ID
 * getarg(0)	-> EventID
 * 
 * This function will return Event prize ID based on Event ID
 * Use: return_Event_Prize( $Event );
 **************/
function	script	return_Event_Prize	{
	if (getarg(0) < 0) return 0;
	return getd("$event_prize_" + getarg(0));
}

/**************
 * Return: Event prize amount
 * getarg(0)	-> EventID
 * 
 * This function will return Event prize amount based on Event ID
 * Use: return_Event_Amount( $Event );
 **************/
function	script	return_Event_Amount	{
	if (getarg(0) < 0) return 0;
	return getd("$event_amount_" + getarg(0));
}

/**************
 * Return: Event Name and Label for enable Event.
 * getarg(0)	-> EventID
 * 
 * This function will return Event Name and Label for enable Event based on Event ID
 * Use: return_Enable_NPC( $Event );
 **************/
function	script	return_Enable_NPC	{
	if (getarg(0) < 0) return "";
	return getd("$event_enable_" + getarg(0) + "$");
}

/**************
 * Return: Event Name and Label for disable Event.
 * getarg(0)	-> EventID
 * 
 * This function will return Event Name and Label for disable Event based on Event ID
 * Use: return_Disable_NPC( $Event );
 **************/
function	script	return_Disable_NPC	{
	if (getarg(0) < 0) return "";
	return getd("$event_disable_" + getarg(0) + "$");
}

/**************
 * Return: Full Event Name (RFYL -> Run for your Life and etc.)
 * getarg(0)	-> EventID
 * 
 * This function will return Full Event Name based on Event ID
 * Use: return_Event_DescName( $Event );
 **************/
function	script	return_Event_DescName	{
	if (getarg(0) < 0) return "";

	switch (getarg(0)) {
		case 0: default:
			return "Empty";
		case 1: // RFYL
			return "Run for your Life";
		case 2: // Kaboom
			return "Explosive Porings";
		case 3:
			return "RFYL with Surprise!";
	}
}

/**************
 * Return: Maximum players to start event.
 * getarg(0)	-> EventID
 * 
 * This function will return maximum players to start event based on Event ID
 * Use: return_MaxPlayers( $Event );
 **************/
function	script	return_MaxPlayers	{
	if (getarg(0) < 0) return 0;
	return getd("$event_max_players_" + getarg(0));
}

/**************
 * Return: Minimum players to start event.
 * getarg(0)	-> EventID
 * 
 * This function will return minimum players to start event based on Event ID
 * Use: return_MinPlayers( $Event );
 **************/
function	script	return_MinPlayers	{
	if (getarg(0) < 0) return 0;
	return getd("$event_min_players_" + getarg(0));
}