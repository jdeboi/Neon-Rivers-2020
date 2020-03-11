#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "ofxArtnet.h"
#include "Tributary.h"


class ofApp : public ofBaseApp{

	public:

		// built-in to openframeworks
		void setup();
		void update();
		void draw();

		// simulation
		void setupSimulation();
		void updateSimulation();
		void pulseGradient(int num);
		void drawTributary(int ind);
		bool pulsing;
		uint64_t lastChecked;
		int pulseTime;
		int numTracked;
		ofColor gradientColors[9];
		ofColor glitchColors[9];

		// SVG
		ofxSVG svg;
		float step;
		vector<Tributary> tributaries;
		vector<ofPoint> points;

		//DECLARE AN ARTNET NODE
		ofxArtnetSender anNode;
		ofxArtnetMessage anMessage;

		//DECLARE DMX DATA = 512 BYTES
		unsigned char dmxData[8][512];
		void setDMXTributaries();

		// mode
		int numSelect;
		int modeSelect;
		void setMode();
		void changeMode();
		float modeTime;
		int modeDuration;

		// colors
		float storedColors[9][3];
		float storedGlitchColors[4][3];
		void initColors();
		void setStoredColors();
		void setGradientColors();

		// transitioning
		bool transitioning;
		ofColor previousColors[9];
		bool checkTransitioning();
		void startTransitioning();


};
