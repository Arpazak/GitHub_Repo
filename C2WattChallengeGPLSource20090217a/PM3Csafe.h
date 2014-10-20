/*******************************************************************************
********************************************************************************

   COPYRIGHT © 2003 Concept 2

   Contains confidential and proprietary information which may not be copied,
   disclosed or used by others except as expressly authorized in writing
   by Concept 2.

   PM3DDI.h   External Interface Definitions for the PM3 CSAFE Protocol 
				  Interface DLL.

   About:     This module contains the DLL external interface definitions
				  that allow PC-based applications to communicate with PM3s
              using the CSAFE protocol.

   Target:        Win32 Compatible

   Written for:   Concept 2
                  105 Industrial Park Drive
                  Morrisville, VT 05661
                  802-888-5225 (Voice)
                  802-888-6331 (Fax)

   Contacts:      Scott Hamilton 
                  802-888-5226 x3062 (Voice)
                  scotth@concept2.com

   Written by:    Rob Macklin / Andrew Dombek
                  Microprocessor Designs, Inc.
                  65 Longmeadow Drive
                  PO Box 160
                  Shelburne, VT 05482
                  http://www.updesigns.com

   $Revision: 1 $

--------------------------------------------------------------------------------
   $Log: /Concept II/C2PM3/Pc_src/SDK Release/PM3Csafe.h $
 * 
 * 1     3/10/05 5:23p Adomb
 * Branched a new release directory from the RowPro release, due to the
 * fact that we want an empty CSAFE INI file for public SDK.
 * 
 * 2     9/16/04 1:11p Adomb
 * Updated PM3CsafeDLL so that it is compatible with standard 'C' linking.
 * Recompiled the PM3APIDemo application.
 * 
 * 1     9/09/04 9:01a Adomb
 * 
 * 2     6/09/04 9:56a Adomb
 * Added API function to retrieve CSAFE slave status byte.  Modified code
 * to make every non-PM3 packet a standard CSAFE frame.
 * 
 * 1     10/07/03 4:23p Adomb
 * Release 1.10 - Branched DLL from LogCard Utility.  INI files renamed
 * with "RP" on the front.
 * 
 * 1     10/07/03 7:17a Adomb
 * Moved workspace
 * 
 * 7     7/09/03 5:51p Adomb
 * Release 1.08 - Added code to deal with differing LogCard read block
 * sizes with different releases of firmware.  Anything version 45 or
 * below is 32 bytes per block.  Anything above verions 45 is 64 bytes per
 * block.
 * 
 * 6     7/09/03 3:11p Adomb
 * Release 1.07 - Changed registry key from Concept 2 to Concept2.
 * Changed LogCard read block size from 32 to 64 bytes.
 * 
 * 5     6/16/03 4:11p Adomb
 * V1.03 - Supports reading the log card.  Additional error checking.
 * 
 * 3     6/10/03 11:19a Adomb
 * Release 1.02 - Added additional error checking.  Fixed problem with the
 * way the registry was being written for the .INI file.
 * 
 * 2     6/05/03 5:04p Adomb
 * DLL Release 1.01 - Fixed bug with buffer allocation, added error
 * checking
 * 
 * 1     6/05/03 9:48a Adomb
 * DLL Release 1.0 - For Peter L.
 * 
 * 1     xx/xx/03 xx:xxa Adomb
 * Initial check-in
 * 
********************************************************************************
*******************************************************************************/
#ifndef _PM3CSAFE_H
#define _PM3CSAFE_H

#ifdef _MSC_VER
   #ifdef PM3CSAFE_EXPORTS
   #define PM3CSAFE_API extern "C" __declspec(dllexport)
   #else
   #define PM3CSAFE_API extern "C" __declspec(dllimport)
   #endif
#else
   #define PM3CSAFE_API
#endif

/*
 * CSAFE status byte definition
 */
#define SLAVE_STATE_MASK         0x0f
#define PREV_FRAME_STATUS_MASK   0x30
#define FRAME_COUNT_MASK         0X80

#define GET_SLAVE_STATE(val)     (val & SLAVE_STATE_MASK)
#define GET_FRAME_STATUS(val)    ((val & PREV_FRAME_STATUS_MASK) >> 4)
#define GET_FRAME_COUNT(val)     ((val & FRAME_COUNT_MASK) >> 7)

enum SLAVE_STATES {
   STATE_ERROR,
   STATE_READY,
   STATE_IDLE,
   STATE_HAVEID,
   STATE_INUSE=5,
   STATE_PAUSED,
   STATE_FINISHED,
   STATE_MANUAL,
   STATE_OFFLINE
};

enum SLAVE_STATUSES {
   STATUS_OK,
   STATUS_PREV_REJECT,
   STATUS_PREV_BAD,
   STATUS_PREV_NOT_READY
};

/*******************************************************************************
 *******************************************************************************
								  Definitions
********************************************************************************
*******************************************************************************/
#define TKFRAME_CSAFE_FRAME_STD_TYPE            0
#define TKFRAME_CSAFE_FRAME_EXT_TYPE            1

#define TKCMDSET_PROGRESS_MESSAGE_TIME   100			// Rate to message Windows app (in ms)

#define CSAFE_BUFFER_SIZE				256
#define CSAFE_DATA_MAXSIZE			   128-5   // Data max is half of frame maxsize to account for 
                                            // "stuffing", minus 5 bytes header/checksum info
// Max number of PM3 commands
#define MAX_PM3_CMDS                256
// Max number of chars in an INI file key string
#define MAX_INI_FIELD_TEXT_LEN      128
// Max number of data types for a particular command or response
#define MAX_INI_TYPES_PER_CMD       24

/*
 * Log Card definitions
 */
#define MAX_LOG_CARD_SIZE			65535	// Maximum size of log card
#define LOGCARD_BLOCK_SIZE			64		// #bytes to read/write at a time to/from logcard
#define OLD_LOGCARD_BLOCK_SIZE	32

#define PM3_CMDTYPE_BYTE_LOC				0	// Log card command frame
#define PM3_CMD_BYTE_LOC					1
#define PM3_LOGCARD_CMD_ADDRESS_LOC		2
#define PM3_LOGCARD_CMD_BLOCK_SIZE_LOC	3
#define PM3_LOGCARD_CMD_DATA_SIZE		4

#define PM3_LOGCARD_RSP_CMDTYPE_LOC		0	// Log card response frame
#define PM3_LOGCARD_RSP_CMD_LOC			1	
#define PM3_LOGCARD_RSP_DATA_COUNT_LOC	2	
#define PM3_LOGCARD_RSP_DATA_LOC			3	


#define PM3_GET_HW_ADDRESS_CMD_DATA_SIZE	2		// Get serial# command
#define PM3_GET_HW_ADDRESS_RSP_DATA_LOC	2

#define PM3_GET_FW_VERSION_CMD_DATA_SIZE	2		// Get version# command
#define PM3_GET_FW_VERSION_RSP_DATA_LOC	2

#define PM3_SET_AUTHEN_PW_HW_ADR_LOC			2	// Set authentication password command frame
#define PM3_SET_AUTHEN_PW_MSB_AUTHEN_PW_LOC	3
#define PM3_SET_AUTHEN_PW_LSB_AUTHEN_PW_LOC	4
#define PM3_SET_AUTHEN_PW_CMD_DATA_SIZE		5
#define PM3_SET_AUTHEN_PW_RSP_DATA_LOC			2


/*
 * Data type map.
 */
#define TKCMDSET_UNDEFINED_TYPE        0
#define TKCMDSET_DATA_TYPE_BYTE        1
#define TKCMDSET_DATA_TYPE_INT2        2
#define TKCMDSET_DATA_TYPE_INT3        3
#define TKCMDSET_DATA_TYPE_INT4        4
#define TKCMDSET_DATA_TYPE_FLOAT       5
#define TKCMDSET_DATA_TYPE_STRING      6

 /*
 * Command type map.
 */
#define TKCMDSET_SHORT_PULL_CONFIG  1
#define TKCMDSET_SHORT_PUSH_CONFIG  2
#define TKCMDSET_SHORT_PUSH_DATA    3
#define TKCMDSET_SHORT_PULL_DATA    4
#define TKCMDSET_LONG_PULL_CONFIG   5
#define TKCMDSET_LONG_PUSH_CONFIG   6
#define TKCMDSET_LONG_PUSH_DATA     7
#define TKCMDSET_LONG_PULL_DATA     8


/*******************************************************************************
 *******************************************************************************
								  TypeDefs
********************************************************************************
*******************************************************************************/
/* MPD Standard data type definitions */
#ifndef MPD_TYPES
#define MPD_TYPES
typedef unsigned char  UINT8_T;
typedef unsigned short UINT16_T;
typedef unsigned long  UINT32_T;
typedef char           INT8_T;
typedef short          INT16_T;
typedef long           INT32_T;
typedef unsigned char  BOOLEAN_T;
typedef float          FLOAT32_T;
typedef INT16_T        ERRCODE_T;
#endif

typedef struct {
    unsigned char frame_type;
    unsigned char dest_addr;
    unsigned char src_addr;
    unsigned char dest_intf;
    unsigned char src_intf;
} TKFRAME_FRAME_STATUS_T;

/*
 * Information defining the command and response data types
 * for each command is read from the INI file into this struct.
 */
typedef struct {
    UINT8_T cmd_type;
    UINT8_T num_cmd_data_types;
    UINT8_T cmd_data_type[MAX_INI_TYPES_PER_CMD];
    UINT8_T num_rsp_data_types;
    UINT8_T rsp_data_type[MAX_INI_TYPES_PER_CMD];
} TKCMDSET_PM3_COMMAND_T;


/********************************************************************************
   Prototypes for standard DLL functions
********************************************************************************/


/****************************************************************************
   tkcmdsetCSAFE_get_dll_version()

   Returns the current version number of this software.

   Inputs:     None

   Outputs:    None
   
   Returns:    UINT16_T    ver_info    High byte is major version number
                                       Low byte is minor version number

****************************************************************************/
PM3CSAFE_API UINT16_T tkcmdsetCSAFE_get_dll_version(void);

/****************************************************************************
   tkcmdsetCSAFE_get_error_name

   About:      Returns the name of the error associated with the code

   Inputs:     ERRCODE_T   ecode       Code to be looked up
               UINT16_T    namelen     Maximum length of name string

   Outputs:    char *      nameptr     Location to place name string

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3CSAFE_API ERRCODE_T tkcmdsetCSAFE_get_error_name(ERRCODE_T ecode,char * nameptr,
												UINT16_T namelen);

/****************************************************************************
   tkcmdsetCSAFE_get_error_text

   About:      Returns the text description of the error associated with the code

   Inputs:     ERRCODE_T   ecode       Code to be looked up
               UINT16_T    namelen     Maximum length of text description string

   Outputs:    char *      nameptr     Location to place text description string

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3CSAFE_API ERRCODE_T tkcmdsetCSAFE_get_error_text(ERRCODE_T ecode,char * textptr,
												UINT16_T textlen);


/********************************************************************************
   Prototypes for Command Set functions
********************************************************************************/

/****************************************************************************
   tkcmdsetCSAFE_get_cmd_text

   About:      Returns the text description of the PM3 command number

   Inputs:     UINT8_T     cmd         Command number
               UINT16_T    namelen     Maximum length of text description string

   Outputs:    char *      nameptr     Location to place text description string

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3CSAFE_API ERRCODE_T tkcmdsetCSAFE_get_cmd_text(UINT8_T cmd, char * textptr,
												UINT16_T textlen);

/****************************************************************************
   tkcmdsetCSAFE_get_cmd_name

   About:      Returns the text name of the PM3 command number

   Inputs:     UINT8_T     cmd         Command number
               UINT16_T    namelen     Maximum length of text name string

   Outputs:    char *      nameptr     Location to place text name string

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3CSAFE_API ERRCODE_T tkcmdsetCSAFE_get_cmd_name(UINT8_T cmd, char * textptr,
												UINT16_T textlen);

/****************************************************************************
   tkcmdsetCSAFE_get_cmd_data_types

   About:      Returns the command and response data types associated with
					the PM3 command number.

   Inputs:     UINT8_T     cmd						Command number

   Outputs:    UINT8_T *cmd_type						PM3 command type
					UINT8_T *num_cmd_data_types		Number of command data types
					UINT8_T cmd_data_type[]				Array of command data types
					UINT8_T * num_rsp_data_types		Number of response data types
					UINT8_T rsp_data_type[]				Array of response data types

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3CSAFE_API ERRCODE_T tkcmdsetCSAFE_get_cmd_data_types(UINT8_T cmd, UINT8_T *cmd_type, UINT8_T *num_cmd_data_types,
																  UINT8_T cmd_data_type[], UINT8_T * num_rsp_data_types,
																  UINT8_T rsp_data_type[]);

/****************************************************************************
   tkcmdsetCSAFE_init_protocol

   About:      Initializes the DLL error code interface and configures the 
               CSAFE protocol.  Uses extended frame addressing. 
   
   Inputs:     UINT16_T    timeout     Command/response time out in MS

   Outputs:    Nothing

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3CSAFE_API ERRCODE_T tkcmdsetCSAFE_init_protocol(UINT16_T timeout);

/****************************************************************************
   tkcmdsetCSAFE_read_logblk8

   About:      Reads an 8-bit block of data from a logcard memory location.

   Inputs:     UINT16_T    unit_address   Address of PM device
               UINT32_T    logcard_address	Address of logcard memory to read
               UINT32_T    byte_len			Number of bytes to be read
														(0 returns all)
               

   Outputs:    UINT8_T *  val_ptr8			Location to store block of data read
					UINT32_T * num_read			Actual number of bytes read

   Returns:    ERRCODE_T   ecode				Zero if successful
														Error code otherwise

****************************************************************************/
PM3CSAFE_API ERRCODE_T tkcmdsetCSAFE_read_logblk8(UINT16_T unit_address, UINT32_T logcard_address, 
																	  UINT32_T byte_len, UINT8_T *val_ptr8, 
																	  UINT32_T *num_read);

/****************************************************************************
   tkcmdsetCSAFE_command

   About:      Sends a CSAFE command to a PM device and returns
               the response data.  Note: the unit address is determined
               using the DiscoverPM function in the PM3DDI DLL.
   
   Inputs:     UINT16_T    unit_address   Address of PM device
               UINT16_T     cmd_data_size  Size of cmd data     
               UINT32_T    cmd_data[]     Command data

   Outputs:    UINT16_T     *rsp_data_size Size of rsp data
               UINT32_T    rsp_data[]     Response data

   Returns:    ERRCODE_T   ecode       Zero if successful
                                       Error code otherwise

****************************************************************************/
PM3CSAFE_API ERRCODE_T tkcmdsetCSAFE_command(UINT16_T unit_address,
                                             UINT16_T cmd_data_size, UINT32_T cmd_data[],
                                             UINT16_T *rsp_data_size, UINT32_T rsp_data[]);

/****************************************************************************
   tkcmdsetCSAFE_get_status

   About:      Gets the CSAFE status byte from the previous transaction.
   
   Inputs:     Nothing

   Outputs:    Nothing

   Returns:    UINT8_T     slave_status   CSAFE status byte

****************************************************************************/
PM3CSAFE_API UINT8_T tkcmdsetCSAFE_get_status(void);

#endif /* _PM3CSAFE_H */
