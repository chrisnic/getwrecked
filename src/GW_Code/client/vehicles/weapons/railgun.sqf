//
//      Name: fireRail
//      Desc: Fires a very fast projectile that destroys any vehicles in its path
//      Return: None
//

private ["_obj"];

_this spawn {
	
	params ['_obj', '_target', '_vehicle'];
	_repeats = 1;
	_projectileSpeed = 2000;
	

	[		
		[
			_obj,
			"railgun",
			50
		],
		"playSoundAll",
		true,
		false
	] call bis_fnc_mp;	

	_vel= velocity _vehicle;
	_totalVel = [0,0,0] distance _vel;
	_shake = if (_totalVel > 15) then { 3 } else { (_totalVel / 5) + 0.6 };
	_null = _shake spawn { addCamShake [_this, 5,150]; };

	Sleep 1.8;

	[
		[
			_obj,
			1,
			0.1
		],
		"magnetEffect"
	] call bis_fnc_mp;

	_dir = [GW_TARGET_DIRECTION] call normalizeAngle;

	_oPos = _obj modelToWorld [3,0,-0.7];

	_indirect = (_this select 0) call isIndirect;

	// Can we use the mouse cursor to aim or are we firing indirectly?
	_tPos = if (_indirect) then {
		_dir = if (typeOf _obj == "GroundWeaponHolder") then { ([(getDir _obj) + 90] call normalizeAngle) } else { (getDir _obj) };
		(_obj modelToWorldVisual [200, 0, 0.2])
	} else { GW_TARGET };

	_heading = if (_indirect) then { ([_oPos,_tPos] call BIS_fnc_vectorFromXToY) } else { GW_CAMERA_HEADING };
	_velocity = [_heading, _projectileSpeed] call BIS_fnc_vectorMultiply; 

	_bullet = createVehicle ["M_Titan_AA_static", _oPos, [], 0, "FLY"];

	_bullet disableCollisionWith _obj;
	_bullet disableCollisionWith _vehicle;

	_power = -20;
	_vehicle setVelocity [(_vel select 0)+(sin _dir*_power),(_vel select 1)+(cos _dir*_power),(_vel select 2) + 0.4];	

	playSound3D ["a3\sounds_f\sfx\special_sfx\sparkles_wreck_2.wss", _obj, false, ATLtoASL _oPos, 2, 1, 50];	

	[(ATLtoASL _oPos), (ATLtoASL _tPos), "RLG"] call markIntersects;				
	[(ATLtoASL _oPos), (ATLtoASL _tPos), GW_CURRENTVEHICLE, 0.1, "RLG"] call damageIntersects;
	
	_bullet setVectorDir _heading; 
	_bullet setVelocity _velocity; 

};

true