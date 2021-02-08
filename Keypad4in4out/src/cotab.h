//------------------------------------------------------------------
// $Workfile: app_data.c $   
// $Archive: /eib_stk/appl_example/empty/src/app_data.c $     

// $Author: Adler_K $         
// 
// Copyright Tapko Technologies GmbH
// 
// $Date: 2015-05-06 12:44:24 +0200 (Mi, 06 Mai 2015) $
// $Revision: 1580 $         
//------------------------------------------------------------------
/// @addtogroup KAI_GCO 
/// @{

/** defines the individual address of the KNX device
*/
#define KNX_DEF_INDIVIDUAL_ADDR EIB_ADDR(0x1508)

/**
defines the current length of the address table
@see APP_addrTabSize
*/
#define KNX_CURRENT_ADDR_TAB_LEN 9

/*'
defines the current length of the association table
@see APP_assocTabSize
*/
#define KNX_CURRENT_ASSOC_TAB_LEN 9

//------------------------------------------------------------------
// this block is used for generation of documentation
//------------------------------------------------------------------
#ifdef KAI_GENERATE_DOC
/**
This makro is used to define the addresses, association, communication objects and enums for the communication objects.
The order of the makros defines the order of the group communication objects.
\n There are restictions on the associated addresses. 
- There is a 1 to 1 assignmet for group addresses to the group communication objects.
- The group addresses has to be in ascending order.

@param index  name for the numeration of the group communication object
@param groupAddr group address for this communication object
@param dataPtr pointer to the data of the communication object
@param objType type of the communication object
@param DPT data point type (DPT) of the communication object. The value of this field can be 
- DPT_1, DPST_1_1: these values are used by the ETS manufacturer tool ('_' are replaced by '-')
- DPT_switch: there is a set of DPT name which are translated via kai2ets (see kai2ets.xml)
@param flags configuration flags of the communication object
@param priority priority of the communication object0

@code 
DEFINE_COMM_OBJ(CO_in0,  ETS_GROUP3(2,0,0), RAM_PTR(in0), CO_TypeUint1, DPST_1_1, CO_WU, CO_PRIO_L),
@endcode 
*/
#define DEFINE_COMM_OBJ(index,  groupAddr, dataPtr, objType, DPT, flags, priority),
#endif

START_TAB()
DEFINE_COMM_OBJ(CO_in0,  ETS_GROUP3(2,0,0), RAM_PTR(in0), CO_TypeUint1, DPT_1, CO_RWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_in1,  ETS_GROUP3(2,0,1), RAM_PTR(in1), CO_TypeUint1, DPT_1, CO_RWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_in2,  ETS_GROUP3(2,0,2), RAM_PTR(in2), CO_TypeUint1, DPT_1, CO_RWU, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_in3,  ETS_GROUP3(2,0,3), RAM_PTR(in3), CO_TypeUint1, DPT_1, CO_RWU, CO_PRIO_L)

DEFINE_COMM_OBJ(CO_out0, ETS_GROUP3(2,0,4), RAM_PTR(out0), CO_TypeUint1, DPST_1_1, CO_RT, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_out1, ETS_GROUP3(2,0,5), RAM_PTR(out1), CO_TypeUint1, DPST_1_1, CO_RT, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_out2, ETS_GROUP3(2,0,6), RAM_PTR(out2), CO_TypeUint1, DPST_1_1, CO_RT, CO_PRIO_L)
DEFINE_COMM_OBJ(CO_out3, ETS_GROUP3(2,0,7), RAM_PTR(out3), CO_TypeUint1, DPST_1_1, CO_RT, CO_PRIO_L)

DEFINE_COMM_OBJ(CO_keypass, ETS_GROUP3(2,0,8), RAM_PTR(keypass), CO_TypeByte4, DPT_12, CO_RT, CO_PRIO_L)

END_TAB()

///@}
