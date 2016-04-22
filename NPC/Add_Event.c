function	script	AddEvent	{

	setd "$event_name_" + getarg(9) + "$", getarg(0);
	setd "$event_enable_" + getarg(9) + "$", getarg(1);
	setd "$event_disable_" + getarg(9) + "$", getarg(2);

	setd "$event_prize_" + getarg(9), getarg(3);
	setd "$event_amount_" + getarg(9), getarg(4);
	setd "$event_max_players_" + getarg(9), getarg(5);

	setd "$event_map_name_" + getarg(9) + "$", getarg(6);
	setd "$event_map_x_" + getarg(9), getarg(7);
	setd "$event_map_y_" + getarg(9), getarg(8);
	setd "$event_" + getarg(0), getarg(9);

	setd "$event_min_players_" + getarg(9), getarg(10);
	
	$EVT_Count ++;
	return;
}