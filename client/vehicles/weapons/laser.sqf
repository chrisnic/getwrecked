//
//      Name: fireLaser
//      Desc: Fires a laser at the target, that sets light to vehicles in path
//      Return: None
//

private ["_obj"];

_obj = _this select 0;
_target = _this select 1;
_vehicle = _this select 2;

_repeats = 15;
_projectileSpeed = 1000;

_oPos = (ASLtoATL getPosASL _obj);
_tPos = if (typename _target == 'OBJECT') then { (ASLtoATL getPosASL _target) } else { _target };

_points = [_obj, _tPos];

[
	[
		[[1,0,0,1], 1, _points]
	],
	"laserLine"
] call BIS_fnc_MP;

playSound3D ["a3\sounds_f\sfx\special_sfx\sparkles_wreck_2.wss", _obj, false, _oPos, 1, 1, 50];	

for "_i" from 1 to _repeats step 1 do {

	_oPos = (ASLtoATL getPosASL _obj);
	_oPos set [2, (_oPos select 2) + 0.4]; // Adjusted center of laser

	[
		[
			_obj
		],
		"muzzleEffect"
	] call BIS_fnc_MP;

	_tPos = if (typename _target == 'OBJECT') then { (ASLtoATL getPosASL _target) } else { _target };

	_heading = [_oPos,_tPos] call BIS_fnc_vectorFromXToY;
	_velocity = [_heading, _projectileSpeed] call BIS_fnc_vectorMultiply; 

	_bullet = createVehicle ["B_127x99_Ball_Tracer_Red", _oPos, [], 0, "CAN_COLLIDE"];
	_bullet setVectorDir _heading; 
	_bullet setVelocity _velocity; 

	[ATLtoASL _oPos, ATLtoASL _tPos, (vehicle player), 10] spawn burnIntersects;

	Sleep 0.05;

};