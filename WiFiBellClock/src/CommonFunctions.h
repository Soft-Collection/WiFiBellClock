#if !defined(__COMMON_FUNCTIONS_H__)
#define __COMMON_FUNCTIONS_H__

#include <Arduino.h>

//***************
//* Version 004 *
//***************

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
//---------------------------------------------------------------------------------------------------------
#define min(a,b)                                ((a)<(b)?(a):(b))
#define max(a,b)                                ((a)>(b)?(a):(b))
#define limited(lowestvalue,value,highestvalue) (max((lowestvalue),(min((value),(highestvalue)))))
//#define round(x)                                (((x)>=0)?(int32_t)((x)+0.5):(int32_t)((x)-0.5))
#define sq(x)                                   ((x)*(x))
//#define abs(a)                                  (((a) > 0) ? (a) : (-(a)))
#define radians(deg)                            ((deg)*DEG_TO_RAD)
#define degrees(rad)                            ((rad)*RAD_TO_DEG)
//---------------------------------------------------------------------------------------------------------
inline uint32_t pow_ui(uint32_t a, uint8_t b){uint32_t retVal = 1; uint8_t i = 0; for (i = 0; i < b; i++){ retVal *= a; } return (retVal); };
//---------------------------------------------------------------------------------------------------------
#define get_decimal_digit(value,index)          (((value) / pow_ui(10,(index))) % 10)
#define set_decimal_digit(value,index,digit)    ((value) = ((value) + (((digit) - get_decimal_digit((value),(index))) * pow_ui(10,(index)))))
//---------------------------------------------------------------------------------------------------------
#define bit_read(value,bit) (((value) >> (bit)) & 0x01)
#define bit_set(value,bit) ((value) |= (1UL << (bit)))
#define bit_clear(value,bit) ((value) &= ~(1UL << (bit)))
#define bit_write(value,bit,bitvalue) (bitvalue ? bit_set(value, bit) : bit_clear(value, bit))
#define bits_swap(value,bit1,bit2) ((value) = ((((value) >> (bit1)) ^ ((value) >> (bit2))) & 1) ? (((value) ^ (1 << bit1)) ^ (1 << bit2)) : (value))
//---------------------------------------------------------------------------------------------------------
#define set_bit_of_byte_array(array,bit)    (((uint8_t*)(array))[(bit) >> 3] |=   (1 << ((bit) & 7)))
#define clear_bit_of_byte_array(array,bit)  (((uint8_t*)(array))[(bit) >> 3] &= (~(1 << ((bit) & 7))))
#define read_bit_of_byte_array(array,bit)  ((((uint8_t*)(array))[(bit) >> 3] >> ((bit) & 7)) & 1)
//---------------------------------------------------------------------------------------------------------
#define invert_bit(value,invert) ((value)^(invert))
//---------------------------------------------------------------------------------------------------------
#define is_neighbor(x,y,proximity) (((x) != (y)) && (abs((x) - (y)) <= (proximity)))
//---------------------------------------------------------------------------------------------------------
#define compose_ip_address(ip1,ip2,ip3,ip4) ((((uint32_t)(ip1)) << 24) & (((uint32_t)(ip2)) << 16) & (((uint32_t)(ip3)) << 8) & ((uint32_t)(ip1)))
//---------------------------------------------------------------------------------------------------------
#define plus_modulo(value,valueToAdd,modulo) (((value)+(valueToAdd))<(modulo))?((value)+(valueToAdd)):((value)+(valueToAdd)-(modulo))
#define minus_modulo(value,valueToSubtract,modulo) (((value)-(valueToSubtract))>=0)?((value)-(valueToSubtract)):((value)+(modulo)-(valueToSubtract))
#define add_modulo(value,valueToAdd,modulo) ((value) = (plus_modulo((value),(valueToAdd),(modulo))))
#define subtract_modulo(value,valueToSubtract,modulo) ((value) = (minus_modulo((value),(valueToSubtract),(modulo))))
#define increment_modulo(value,modulo) ((value) = (((value) < ((modulo) - 1)) ? (value) + 1 : 0))
#define decrement_modulo(value,modulo) ((value) = (((value) > 0) ? (value) - 1 : (modulo) - 1))
//---------------------------------------------------------------------------------------------------------
#define plus_time(time_val,valueToAdd) ((time_val)+(valueToAdd))
#define minus_time(time_val,valueToSubtract) ((time_val)-(valueToSubtract))
#define increment_time(time_val) ((time_val) = (plus_time(time_val, 1)))
#define decrement_time(time_val) ((time_val) = (minus_time(time_val, 1)))
#define bigger_time(time_val1,time_val2) (minus_time((time_val1),(time_val2)) < 0x80000000)
//---------------------------------------------------------------------------------------------------------
#define objcpy(dst,src) memcpy((dst), (src), sizeof(*(src)))
#define objset(dst,val) memset((dst), (val), sizeof(*(dst)))
#define objzero(dst)    objset((dst),0)
//---------------------------------------------------------------------------------------------------------
#define update_minimum(dst,value) (dst) = (min((dst),(value)))
#define update_maximum(dst,value) (dst) = (max((dst),(value)))
//---------------------------------------------------------------------------------------------------------
#define averageint int64_t
#define TIME_NOT_SET -1
//---------------------------------------------------------------------------------------------------------

#endif // !defined(__COMMON_FUNCTIONS_H__)
