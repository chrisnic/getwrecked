//
//      Name: fireRpg
//      Desc: Fires a dumbfire missile that carries a mild explosive 
//      Return: None
//

private ['_gun', '_target', '_vehicle'];

_gun = _this select 0;
_target = _this select 1;

_repeats = 1;
_round = "R_PG32V_F";
_soundToPlay = "a3\sounds_f\weapons\Launcher\nlaw_final_2.wss";
_fireSpeed = 0.1;
_projectileSpeed = 350;
_range = 60;

[
	[
		_gun
	],
	"muzzleEffect"
] call BIS_fnc_MP;

addCamShake [.5, 1,20];

for "_i" from 1 to _repeats step 1 do {

	_targetPos = if (typename _target == 'OBJECT') then { getPosASL _target } else { _target };
	_gPos = _gun  modelToWorldVisual [1,0,-0.7];

	if (GW_DEBUG) then { [_gPos, _targetPos, 3] spawn debugLine; };

	_targetPos = [(ASLtoATL _targetPos), 2, 2, 1] call setVariance;
	_heading = [(ASLtoATL _gPos), (ASLtoATL _targetPos)] call BIS_fnc_vectorFromXToY;
	_velocity = [_heading, _projectileSpeed] call BIS_fnc_vectorMultiply; 

	_bullet = createVehicle [_round, _gPos, [], 0, "FLY"];

	[(ATLtoASL _gPos), (ATLtoASL _targetPos)] call markIntersects;

	_bullet setVectorDir _heading; 
	_bullet setVelocity _velocity; 

	playSound3D [_soundToPlay, _gun, false, getPos _gun, 1, 1, 50];		

	Sleep _fireSpeed;
};



true
