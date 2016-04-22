function	script	Event_Winner	{
	query_sql( "SELECT `account_id` FROM `char` WHERE `char_id` = " + getarg(0), .@WinAID );
	attachrid( .@WinAID );
	Event_Win_IDs[ Event_Win_Cnt ] = getarg(1);
	Event_Win_Cnt ++;
	Event_Wins ++;
	message strcharinfo(0), "Congratulations! Use '@event' command!";
	announce "[Event Manager]: Event " + return_Event_Name( getarg(1) ) + " ended! Congratulations " + strcharinfo(0) + "!", bc_all, C_AQUA;
	//query_sql( "UPDATE daily_winners SET winner = '" + strcharinfo(0) + "' WHERE event = " + return_Event_Name( getarg(1) ) );
	detachrid;
	return;
}