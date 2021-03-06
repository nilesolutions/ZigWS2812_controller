/*****************************************************************************
 *
 * MODULE:             None colour Scene Remote
 *
 * COMPONENT:          none_colour_scene_remote.h
 *
 * AUTHOR:             rclay
 *
 * DESCRIPTION:        Header for ZigBee Light Link Non Colour Scene Remote profile functions
 *
 * $HeadURL: https://www.collabnet.nxp.com/svn/lprf_sware/Projects/SmartEnergy/Branches/UnifiedZCL_ZLL102_HA122_Maintenance/Profiles/ZLL/Include/non_colour_scene_remote.h $
 *
 * $Revision: 88125 $
 *
 * $LastChangedBy: nxp29741 $
 *
 * $LastChangedDate: 2017-04-27 18:26:12 +0100 (Thu, 27 Apr 2017) $
 *
 * $Id: non_colour_scene_remote.h 88125 2017-04-27 17:26:12Z nxp29741 $
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products  [NXP Microcontrollers such as JN5168, JN5164,
 * JN5161, JN5148, JN5142, JN5139]. 
 * You, and any third parties must reproduce the copyright and warranty notice 
 * and any other legend of ownership on each  copy or partial copy of the software.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE. 
 *
 * Copyright NXP B.V. 2012. All rights reserved
 *
 ****************************************************************************/

#ifndef NON_COLOUR_SCENE_REMOTE_H
#define NON_COLOUR_SCENE_REMOTE_H

#if defined __cplusplus
extern "C" {
#endif

#include <jendefs.h>
#include "zcl.h"
#include "zcl_options.h"
#include "zll.h"
#include "Basic.h"
#include "zll_commission.h"
#include "zll_utility.h"
#include "Identify.h"
#include "OnOff.h"
#include "LevelControl.h"
#include "Scenes.h"
#include "Groups.h"


/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/* Holds cluster instances */
typedef struct 
{
    /*
     *  All ZLL devices have following mandatory clusters
     */
    #if (defined CLD_BASIC) && (defined BASIC_SERVER)
        tsZCL_ClusterInstance sBasicServer;
    #endif

    #if (defined CLD_BASIC) && (defined BASIC_CLIENT)
        tsZCL_ClusterInstance sBasicClient;
    #endif

    #if (defined CLD_ZLL_UTILITY) && (defined ZLL_UTILITY_SERVER)
        tsZCL_ClusterInstance sZllUtilityServer;
    #endif

    #if (defined CLD_ZLL_UTILITY) && (defined ZLL_UTILITY_CLIENT)
        tsZCL_ClusterInstance sZllUtilityClient;
    #endif

    /*
     *  Non colour scene Remote device has 5 other mandatory clusters
     */
    #if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
        tsZCL_ClusterInstance sIdentifyClient;
    #endif

    #if (defined CLD_ONOFF) && (defined ONOFF_CLIENT)
        tsZCL_ClusterInstance sOnOffClient;
    #endif

    #if (defined CLD_SCENES) && (defined SCENES_CLIENT)
        tsZCL_ClusterInstance sScenesClient;
    #endif

    #if (defined CLD_GROUPS) && (defined GROUPS_CLIENT)
        tsZCL_ClusterInstance sGroupsClient;
    #endif

    #if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_CLIENT)
        tsZCL_ClusterInstance sLevelControlClient;
    #endif

} tsZLL_NonColourSceneRemoteDeviceClusterInstances;


/* Holds everything required to create an instance of a Non Colour Scene Remote */
typedef struct
{
    tsZCL_EndPointDefinition sEndPoint;

    /* Cluster instances */
    tsZLL_NonColourSceneRemoteDeviceClusterInstances sClusterInstance;

    #if (defined CLD_BASIC) && (defined BASIC_SERVER)
        /* Basic Cluster - Server */
        tsCLD_Basic sBasicServerCluster;
    #endif

    #if (defined CLD_BASIC) && (defined BASIC_CLIENT)
        /* Basic Cluster - Client */
        tsCLD_Basic sBasicClientCluster;
    #endif

    #if (defined CLD_ZLL_UTILITY) && (defined ZLL_UTILITY_SERVER)
        /* Utility Cluster - Server */
        tsCLD_ZllUtility                         sZllUtilityServerCluster;
        tsCLD_ZllUtilityCustomDataStructure  sZllUtilityServerCustomDataStructure;
    #endif

    #if (defined CLD_ZLL_UTILITY) && (defined ZLL_UTILITY_CLIENT)
        /* Utility Cluster - Client */
        tsCLD_ZllUtility                         sZllUtilityClientCluster;
        tsCLD_ZllUtilityCustomDataStructure  sZllUtilityClientCustomDataStructure;
    #endif

        /* Mandatory client clusters */
    #if (defined CLD_IDENTIFY) && (defined IDENTIFY_CLIENT)
        /* Identify Cluster - Client */
        tsCLD_Identify sIdentifyClientCluster;
        tsCLD_IdentifyCustomDataStructure sIdentifyClientCustomDataStructure;
    #endif

    #if (defined CLD_ONOFF) && (defined ONOFF_CLIENT)
        /* On/Off Cluster - Client */
        tsCLD_OnOff sOnOffClientCluster;
    #endif

    #if (defined CLD_LEVEL_CONTROL) && (defined LEVEL_CONTROL_CLIENT)
        /* Level Control Cluster - Client */
        tsCLD_LevelControl sLevelControlClientCluster;
        tsCLD_LevelControlCustomDataStructure sLevelControlClientCustomDataStructure;
    #endif

    #if (defined CLD_SCENES) && (defined SCENES_CLIENT)
        /* Scenes Cluster - Client */
        tsCLD_Scenes sScenesClientCluster;
        tsCLD_ScenesCustomDataStructure sScenesClientCustomDataStructure;
    #endif

    #if (defined CLD_GROUPS) && (defined GROUPS_CLIENT)
        /* Groups Cluster - Client */
        tsCLD_Groups sGroupsClientCluster;
        tsCLD_GroupsCustomDataStructure sGroupsClientCustomDataStructure;
    #endif

} tsZLL_NonColourSceneRemoteDevice;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC teZCL_Status eZLL_RegisterNonColourSceneRemoteEndPoint(uint8 u8EndPointIdentifier,
                                              tfpZCL_ZCLCallBackFunction cbCallBack,
                                              tsZLL_NonColourSceneRemoteDevice *psDeviceInfo);

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/

#endif /* NON_COLOUR_SCENE_REMOTE_H */
