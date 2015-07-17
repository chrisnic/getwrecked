//
//      Name: setCurrentZone
//      Desc: Sets the target zone and equips the boundary point data for use with outOfBounds checks
//      Return: None
//

params ['_z'];
if (_z == "") exitWith {};

{
	if ((_x select 0) == _z) exitWith {
		GW_CURRENTZONE = _z;
		GW_CURRENTZONE_DATA = _x select 1;
	};
	false
} count GW_ZONES > 0;
