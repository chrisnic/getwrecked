_subjects = [
	['Fist', 2],
	['Master', 2],
	['Soldier', 2],
	['Reflex', 2],
	['Inferno', 2],
	['War', 2],
	['Vendetta', 2],
	['Maximum', 0],
	['Sudden', 0],
	['Instant', 0],
	['Battle', 2],
	['Infinite', 0],
	['Duke', 2],
	['Lord', 2],
	['Peasant', 2],
	['Double', 0],
	['Fatal', 0],
	['Quadruple', 2 ],
	['Extreme', 2],
	['Commander', 2],
	['Slave', 2],
	['Total', 0],
	['Dominator',2],
	['Demolisher',2],
	['Destroyer',2],
	['Executioner', 2],
	['Speedy', 0],
	['Captain', 2],
	['Colonel', 2],
	['General', 2],
	['Sergeant', 2],
	['Commodore', 2],
	['Major', 2],
	['Marshal', 2],
	['Absolute', 0],
	['Complete', 0],
	['Sheer', 0],
	['Unlimited', 0],
	['Utter', 0],
	['Simple', 0],
	['Unconditional', 0],
	['Eternal', 0],
	['Perpetual', 0],
	['Immense', 0],
	['Everlasting', 0],
	['Enormous', 0],
	['Colossal', 2],
	['Colossus', 2],
	['Excessive', 0],
	['Gigantic', 0],
	['Monstrous', 0],
	['Dealer', 2]
];

_descriptors = [
	' ',
	' of ',
	' for '	
];

_attributes = [
	'Overkill',
	'Vengeance',
	'Retribution',
	'Danger',
	'Conquest',
	'Termination',
	'Domination',
	'Risk',
	'Punishment',
	'Blood',
	'Execution',
	'Prejudice',
	'Extermination',
	'Justice',
	'Revenge',
	'Death',
	'Jeopardy',
	'Humiliation',
	'Surrender',
	'Intimidation',
	'Victory',
	'Assassination',
	'Action',
	'Honor',
	'Retreat',
	'Payback',
	'Impact',
	'Risk',
	'Domination',
	'Demolition',
	'Speed',
	'Doom',
	'Demise',
	'Defecation'
];

_sub = _subjects select (floor (random (count _subjects)));
_des = _descriptors select (floor (random (_sub select 1)));
_att = _attributes select (floor (random (count _attributes)));

hint toUpper( format['%1%2%3', (_sub select 0), _des, _att] );
