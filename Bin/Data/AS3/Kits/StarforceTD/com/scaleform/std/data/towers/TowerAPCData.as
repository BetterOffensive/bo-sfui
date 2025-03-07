﻿/**************************************************************************

Filename    :   TowerAPCData.as

Copyright   :   Copyright 2012 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

package com.scaleform.std.data.towers
{
    public class TowerAPCData extends TowerData 
    {
        // Infantry Max Speed
        public static const INFANTRY_MAX_SPEED:Number = 100;
        
        // Infantry Spawn Range
        public static const INFANTRY_SPAWN_RANGE:Number = 175;
        
        // Infantry Regen Rate
        public static const INFANTRY_REGEN_RATE:Number = 3;
        
        // Infantry Respawn Rate
        public static const INFANTRY_RESPAWN_RATE:Number = 5;
        
        // Infantry Max Units
        public static const INFANTRY_NUM_MAX_UNITS:Number = 3;
        
    // Initilaization
        public function TowerAPCData(data:XMLList) {
            super(data);
        }
        
    // Protected Functions
        override protected function loadXmlStats(data:XMLList):void {           
            super.loadXmlStats(data);
        
            // Effect
            effectType = TowerData.EFFECT_NONE;
        }
        
    }

}