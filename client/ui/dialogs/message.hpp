#define GW_Dialog_ID 93000
#define GW_Dialog_Input_ID 93001
#define GW_Dialog_Title_ID 93002

#define GW_BUTTON_WIDTH 0.2
#define GW_BUTTON_HEIGHT 0.035

#define GW_BUTTON_GAP_Y 0.005
#define GW_BUTTON_GAP_X 0.0025
#define GW_BUTTON_BACKGROUND {0,0,0,0.7}

#define DIALOG_X (0.5 - (((GW_BUTTON_WIDTH * 1) + 0.03) /2))
#define DIALOG_Y (0.5 - (((GW_BUTTON_HEIGHT * 3) + (GW_BUTTON_GAP_Y * 2) + 0.05) / 2))

#define CT_LISTBOX 5
#define CT_STRUCTURED_TEXT  13
#define CT_EDIT 2

class GW_RscEdit
{
	type = CT_EDIT;
	style = ST_LEFT;
	x = 0;
	y = 0;
	h = 0.05;
	w = 0.2;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,1};
	colorSelection[] = {1,1,1,0.5};
	font = "PuristaLight";
	sizeEx = 0.03;
	autocomplete = false;
	text = "";
	size = 0.2;
	shadow = 0;

	class TextPos
	{
		left = 0.0135;
		top = 0.0135;
		right = 0;
		bottom = 0;
	};
};


class GW_Dialog
{
	idd = GW_Dialog_ID;
	name = "GW_Dialog";
	movingEnabled = false;
	enableSimulation = true;	
	onLoad = "uiNamespace setVariable ['GW_Dialog', _this select 0]; "; 

	class controlsBackground
	{
		
		class MarginBottom : GW_Block
		{
			idc = 93003;
			colorBackground[] = {0,0,0,0.85};
			x = -1;
			y = (MARGIN_BOTTOM + (GW_BUTTON_HEIGHT * 2)) * safezoneH + safezoneY; 
			w = 3;
			h = 0.25 * safezoneH;
		};	

		class MarginTop : GW_Block
		{
			idc = 93004;
			colorBackground[] = {0,0,0,0.85};
			x = -1;
			y = 0 * safezoneH + safezoneY; 
			w = 3;
			h = MARGIN_TOP + (GW_BUTTON_HEIGHT) * safezoneH;
		};	

		class StripeTile : GW_Stripe_Box
		{    
			idc = -1;			
			x = (DIALOG_X) * safezoneW + safezoneX;
			y = (DIALOG_Y + (GW_BUTTON_GAP_Y * 2) + (GW_BUTTON_HEIGHT * 2)) * safezoneH + safezoneY;
			w = ((GW_BUTTON_WIDTH * 0.5) - (GW_BUTTON_GAP_X / 2)) * safezoneW;
			h = GW_BUTTON_HEIGHT * safezoneH;	

			tileW = 1.75; 
			tileH = 0.595;
		};  
		
		class DialogBackground : GW_Block
		{
			idc = 93000;
			colorBackground[] = {0,0,0,0.25};
			x = (DIALOG_X - 0.015) * safezoneW + safezoneX;
			y = (DIALOG_Y - 0.025) * safezoneH + safezoneY;
			w = ((GW_BUTTON_WIDTH * 1) + 0.03) * safezoneW;
			h = ((GW_BUTTON_HEIGHT * 3) + (GW_BUTTON_GAP_Y * 2) + 0.05) * safezoneH;
		};	

		class InputBackground : GW_Block
		{
			idc = -1;
			colorBackground[] = {0,0,0,0.5};			
			x = (DIALOG_X) * safezoneW + safezoneX;
			y = (DIALOG_Y + (GW_BUTTON_HEIGHT) + (GW_BUTTON_GAP_Y)) * safezoneH + safezoneY;
			w = (GW_BUTTON_WIDTH) * safezoneW;
			h = (GW_BUTTON_HEIGHT) * safezoneH;
		};	

		class CornerA
		{    
				idc = -1;
				type = 0;
				style = 48 + 2048; 				
				x = (DIALOG_X - 0.02) * safezoneW + safezoneX; 
				y = (DIALOG_Y - 0.025) * safezoneH + safezoneY;				
				w = 0.025 * safezoneW;
				h = 0.025 * safezoneH;
				font = "";
				sizeEx = 0.05;
				colorBackground[] = {1,1,1,1}; 
				colorText[] = {1,1,1,0.95}; 
				text = "client\images\icons\hud\corner1.paa";
				lineSpacing = 1; 
		};

		class CornerB
		{    
				idc = -1;
				type = 0;
				style = 48 + 2048; 			
				x = (DIALOG_X + (GW_BUTTON_WIDTH) - 0.0055) * safezoneW + safezoneX; 
				y = (DIALOG_Y - 0.025) * safezoneH + safezoneY;				
				w = 0.025 * safezoneW;
				h = 0.025 * safezoneH;
				font = "";
				sizeEx = 0.05;
				colorBackground[] = {1,1,1,1}; 
				colorText[] = {1,1,1,0.95}; 
				text = "client\images\icons\hud\corner2.paa";
				lineSpacing = 1; 
		};

		class CornerC
		{    
				idc = -1;
				type = 0;
				style = 48 + 2048; 				
				x = (DIALOG_X + (GW_BUTTON_WIDTH) - 0.0055) * safezoneW + safezoneX; 
				y = (DIALOG_Y + (GW_BUTTON_HEIGHT * 3) + (GW_BUTTON_GAP_Y * 2)) * safezoneH + safezoneY;				
				w = 0.025 * safezoneW;
				h = 0.025 * safezoneH;
				font = "";
				sizeEx = 0.05;
				colorBackground[] = {1,1,1,1}; 
				colorText[] = {1,1,1,0.95}; 
				text = "client\images\icons\hud\corner3.paa";
				lineSpacing = 1; 
		};

		class CornerD
		{    
				idc = -1;
				type = 0;
				style = 48 + 2048; 				
				x = (DIALOG_X - 0.02) * safezoneW + safezoneX; 
				y = (DIALOG_Y + (GW_BUTTON_HEIGHT * 3) + (GW_BUTTON_GAP_Y * 2)) * safezoneH + safezoneY;		
				w = 0.025 * safezoneW;
				h = 0.025 * safezoneH;
				font = "";
				sizeEx = 0.05;
				colorBackground[] = {1,1,1,1}; 
				colorText[] = {1,1,1,0.95}; 
				text = "client\images\icons\hud\corner4.paa";
				lineSpacing = 1; 
		};
		
		  	

	};

	class controls
	{
		class InputArea : GW_RscEdit
		{
			idc = GW_Dialog_Input_ID;
			text = "";
			colorBackgroundFocused[] = {0,0,0,0};
			colorBackground[] = {0,0,0,0};
			colorBackground2[] = {0,0,0,0};
			x = (DIALOG_X) * safezoneW + safezoneX;
			y = (DIALOG_Y + GW_BUTTON_HEIGHT + GW_BUTTON_GAP_Y) * safezoneH + safezoneY;
			w = (GW_BUTTON_WIDTH) * safezoneW;
			h = GW_BUTTON_HEIGHT * safezoneH;

		};

		class DialogTitle : GW_RscButtonMenu
		{
			idc = GW_Dialog_Title_ID;
			text = "CONFIRM";
			onButtonClick = "";
			x = (DIALOG_X) * safezoneW + safezoneX;
			y = (DIALOG_Y) * safezoneH + safezoneY;
			w = (GW_BUTTON_WIDTH * 1) * safezoneW;
			h = GW_BUTTON_HEIGHT * safezoneH;

			colorFocused[] = {1,1,1,1};
			color2[] = {1,1,1,1};

			colorBackground[] = GW_BUTTON_BACKGROUND;
			colorBackgroundFocused[] = GW_BUTTON_BACKGROUND;
			colorBackground2[] = GW_BUTTON_BACKGROUND;

			class Attributes
			{
				font = "PuristaLight";
				color = "#E5E5E5";
				align = "left";
				shadow = "false";
			};

			class TextPos
			{
				left = 0.0135;
				top = 0.0135;
				right = 0;
				bottom = 0;
			};
		};

		class ButtonOk : GW_RscButtonMenu
		{
			idc = -1;
			text = "OK";
			size = 0.03;
			sizeEx = "0.03";

			onButtonClick = "[] call confirmCurrentDialog; false";
			x = (DIALOG_X) * safezoneW + safezoneX;
			y = (DIALOG_Y + (GW_BUTTON_GAP_Y * 2) + (GW_BUTTON_HEIGHT * 2)) * safezoneH + safezoneY;
			w = ((GW_BUTTON_WIDTH * 0.5) - (GW_BUTTON_GAP_X / 2)) * safezoneW;
			h = GW_BUTTON_HEIGHT * safezoneH;

			shadow = 1;

			colorBackground[] = {0,0,0,0.5};
			colorBackgroundFocused[] = {0,0,0,0};
			colorBackground2[] = {0,0,0,0.1};

			color[] = {1,1,1,0.75};
			colorFocused[] = {1,1,1,1};
			color2[] = {1,1,1,1};			
			colorText[] = {1,1,1,1};

			class TextPos
			{
				left = 0;
				top = 0.0135;
				right = 0;
				bottom = 0;
			};

		};

		class ButtonCancel : GW_RscButtonMenu
		{
			idc = -1;
			text = "CANCEL";
			size = 0.03;
			sizeEx = "0.03";

			onButtonClick = "[] call cancelCurrentDialog; false";
			x = (DIALOG_X + (GW_BUTTON_WIDTH / 2) + (GW_BUTTON_GAP_X / 2)) * safezoneW + safezoneX;
			y = (DIALOG_Y + (GW_BUTTON_GAP_Y * 2) + (GW_BUTTON_HEIGHT * 2)) * safezoneH + safezoneY;
			w = ((GW_BUTTON_WIDTH * 0.5) - (GW_BUTTON_GAP_X / 2)) * safezoneW;
			h = GW_BUTTON_HEIGHT * safezoneH;

			class TextPos
			{
				left = 0;
				top = 0.0135;
				right = 0;
				bottom = 0;
			};
		};
	};
};