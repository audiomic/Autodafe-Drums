#include "Autodafe.hpp"
#include "snares.h"
#include "dsp/digital.hpp"


struct DrumsSnare : Module {
	enum ParamIds {
        SAMPLETYPE,
     
		NUM_PARAMS
	};
	enum InputIds {
		TRIG_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		AUDIO_OUTPUT,
		NUM_OUTPUTS
	};
    int numsamples = 8;
	SchmittTrigger trigger;
	SchmittTrigger sampletypeselector;
    int sampletype = 1;
    float lights[8]={};
    float light=0;
       unsigned int count1 = 0;
    unsigned int count2 = 0;
    unsigned int count3 = 0;
     unsigned int count4 = 0;
     unsigned int count5 = 0;
     unsigned int count6 = 0;
     unsigned int count7 = 0;
     unsigned int count8 = 0;
    
	
	DrumsSnare();
	void step();



    json_t *toJson() {
                json_t *rootJ = json_object();

                json_object_set_new(rootJ, "sampletype", json_integer(sampletype));

                return rootJ;
        }

        void fromJson(json_t *rootJ) {
                json_t *stateJ = json_object_get(rootJ, "sampletype");
                if (stateJ) {
                        sampletype = json_integer_value(stateJ);
                }
        }


    
};

DrumsSnare::DrumsSnare()
{
	params.resize(NUM_PARAMS);
	inputs.resize(NUM_INPUTS);
	outputs.resize(NUM_OUTPUTS);
	
	trigger.setThresholds(0.0, 1.0);
	
   
    
    
	// disarm
    
    count1  = SNARE_sample1_len;
    count2  = SNARE_sample2_len;
    count3  = SNARE_sample3_len;
    count4  = SNARE_sample4_len;
    count5  = SNARE_sample5_len;
    count6  = SNARE_sample6_len;
    count7  = SNARE_sample7_len;
    count8  = SNARE_sample8_len;
    

    

   


}








void DrumsSnare::step()
{
    
    
    light -= light / 0.75 / gSampleRate;
   
    
    if (sampletypeselector.process(params[SAMPLETYPE].value))
    { light = 1.0;
         if (sampletype<numsamples) {
        sampletype++;
            
         }
        else
        {
            sampletype=1;
        }
    }
    for (int i = 0; i < numsamples; i++) {
        lights[i]=0.0;
  
        lights[sampletype-1]=1.0;
    }
   
    
	if (trigger.process(inputs[TRIG_INPUT].value)) {
		count1 = 0;
        count2 = 0;
        count3 = 0;
        count4 = 0;
        count5 = 0;
        count6 = 0;
        count7 = 0;
        count8 = 0;
        
	}
    
    
	if (sampletype == 1)
    {
                if( count1 < SNARE_sample1_len ) {
                    int16_t sample;
                    sample  = SNARE_sample1[count1++];
                    sample |= SNARE_sample1[count1++] << 8;
                    
                    outputs[AUDIO_OUTPUT].value =  5.0 * (float)sample / SNARE_sample1_len  ;
                } else {
                    outputs[AUDIO_OUTPUT].value =  0.0 ;
                }
    }
    
    
    
    
    if (sampletype == 2)
    {
        if( count2 < SNARE_sample2_len ) {
            int16_t sample;
            sample  = SNARE_sample2[count2++];
            sample |= SNARE_sample2[count2++] << 8;
            
            outputs[AUDIO_OUTPUT].value =  5.0 * (float)sample / SNARE_sample2_len ;
        } else {
            outputs[AUDIO_OUTPUT].value =  0.0 ;
        }
    }
    
    
    
    if (sampletype == 3)
    {
        if( count3 < SNARE_sample3_len ) {
            int16_t sample;
            sample  = SNARE_sample3[count3++];
            sample |= SNARE_sample3[count3++] << 8;
            
            outputs[AUDIO_OUTPUT].value =  5.0 * (float)sample / SNARE_sample3_len ;
        } else {
            outputs[AUDIO_OUTPUT].value =  0.0 ;
        }
    }
    
    
    
    
    
    
    if (sampletype == 4)
    {
        if( count4 < SNARE_sample4_len ) {
            int16_t sample;
            sample  = SNARE_sample4[count4++];
            sample |= SNARE_sample4[count4++] << 8;
            
            outputs[AUDIO_OUTPUT].value =  5.0 * (float)sample / SNARE_sample4_len ;
        } else {
            outputs[AUDIO_OUTPUT].value =  0.0 ;
        }
    }
    
    
    
    if (sampletype == 5)
    {
        if( count5 < SNARE_sample5_len ) {
            int16_t sample;
            sample  = SNARE_sample5[count5++];
            sample |= SNARE_sample5[count5++] << 8;
            
            outputs[AUDIO_OUTPUT].value =  5.0 * (float)sample / SNARE_sample5_len ;
        } else {
            outputs[AUDIO_OUTPUT].value =  0.0 ;
        }
    }
    
    
    
    if (sampletype == 6)
    {
        if( count6 < SNARE_sample6_len ) {
            int16_t sample;
            sample  = SNARE_sample6[count6++];
            sample |= SNARE_sample6[count6++] << 8;
            
            outputs[AUDIO_OUTPUT].value =  5.0 * (float)sample / SNARE_sample6_len ;
        } else {
            outputs[AUDIO_OUTPUT].value =  0.0 ;
        }
    }
    
    
    
    if (sampletype == 7)
    {
        if( count7 < SNARE_sample7_len ) {
            int16_t sample;
            sample  = SNARE_sample7[count7++];
            sample |= SNARE_sample7[count7++] << 8;
            
            outputs[AUDIO_OUTPUT].value =  5.0 * (float)sample / SNARE_sample7_len ;
        } else {
            outputs[AUDIO_OUTPUT].value =  0.0 ;
        }
    }
   
    
    
    
    if (sampletype == 8)
    {
        if( count8 < SNARE_sample8_len ) {
            int16_t sample;
            sample  = SNARE_sample8[count8++];
            sample |= SNARE_sample8[count8++] << 8;
            
            outputs[AUDIO_OUTPUT].value =  5.0 * (float)sample / SNARE_sample8_len ;
        } else {
            outputs[AUDIO_OUTPUT].value =  0.0 ;
        }
    }
    
    
}

DrumsSnareWidget::DrumsSnareWidget()
{
	DrumsSnare *module = new DrumsSnare();
	setModule(module);
	box.size = Vec(15 * 4, 380);

	{
        SVGPanel *panel = new SVGPanel();
        panel->box.size = box.size;
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/DrumsSnare.svg")));
        
        addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(15,   0)));
	addChild(createScrew<ScrewSilver>(Vec(15, 365)));
    
    addParam(createParam<LEDButton>(Vec(21, 60), module, DrumsSnare::SAMPLETYPE, 0.0, 1.0, 0.0));
    
    //addParam(createParam<Davies1900hBlackKnob>(Vec(30, 80), module, DrumsSnare::PITCH, -12, 12.0, 0.0));
    
    
    
    addChild(createValueLight<SmallLight<GreenValueLight>>(Vec(26,65), &module->light));
	
    addChild(createValueLight<SmallLight<GreenValueLight>>(Vec(10,100), &module->lights[0]));
    addChild(createValueLight<SmallLight<GreenValueLight>>(Vec(10,125), &module->lights[1]));
    addChild(createValueLight<SmallLight<GreenValueLight>>(Vec(10,150), &module->lights[2]));
     addChild(createValueLight<SmallLight<GreenValueLight>>(Vec(10,175), &module->lights[3]));
     addChild(createValueLight<SmallLight<GreenValueLight>>(Vec(10,200), &module->lights[4]));
     addChild(createValueLight<SmallLight<GreenValueLight>>(Vec(10,225), &module->lights[5]));
     addChild(createValueLight<SmallLight<GreenValueLight>>(Vec(10,250), &module->lights[6]));
     addChild(createValueLight<SmallLight<GreenValueLight>>(Vec(10,275), &module->lights[7]));

    

	addInput (createInput <PJ3410Port>(Vec( 0, 300), module, DrumsSnare::TRIG_INPUT));
	addOutput(createOutput<PJ3410Port>(Vec(30, 300), module, DrumsSnare::AUDIO_OUTPUT));

}
