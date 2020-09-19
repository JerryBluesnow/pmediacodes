#ifndef parson_parson_h
#define parson_parson_h

#ifdef __cplusplus
extern "C"
{
#endif    
    
#include <stddef.h>   /* size_t */    

#define PARSON_VERSION 20131130

/* Type definitions */
typedef enum json_value_type 
{
    JSONError   = 0,
    JSONNull    = 1,
    JSONString  = 2,
    JSONNumber  = 3,
    JSONObject  = 4,
    JSONArray   = 5,
    JSONBoolean = 6
} JSON_Value_Type;

struct json_object_t;
struct json_array_t; 

    
/* Types and enums */
typedef struct json_object_t JSON_Object;
typedef struct json_array_t  JSON_Array;

typedef union json_value_value 
{
    const char  *string;
    double       number;
    JSON_Object *object;
    JSON_Array  *array;
    int          boolean;
    int          null;
} JSON_Value_Value;

struct json_value_t 
{
    JSON_Value_Type     type;
    JSON_Value_Value    value;
};
typedef struct json_value_t  JSON_Value;

struct json_object_t 
{
    const char **names;
    JSON_Value **values;
    size_t       count;
    size_t       capacity;
};

struct json_array_t 
{
    JSON_Value **items;
    size_t       count;
    size_t       capacity;
};

/* Parses first JSON value in a file, returns NULL in case of error */
JSON_Value  * json_parse_file(const char *filename);

/* Parses first JSON value in a file and ignores comments (/ * * / and //),
   returns NULL in case of error */
JSON_Value  * json_parse_file_with_comments(const char *filename);
    
/*  Parses first JSON value in a string, returns NULL in case of error */
JSON_Value  * json_parse_string(const char *string);

/*  Parses first JSON value in a string and ignores comments (/ * * / and //),
    returns NULL in case of error */
JSON_Value  * json_parse_string_with_comments(const char *string);
    
/* JSON Object */
JSON_Value  * json_object_get_value  (const JSON_Object *object, const char *name);
const char  * json_object_get_string (const JSON_Object *object, const char *name);
JSON_Object * json_object_get_object (const JSON_Object *object, const char *name);
JSON_Array  * json_object_get_array  (const JSON_Object *object, const char *name);
double        json_object_get_number (const JSON_Object *object, const char *name);
int           json_object_get_boolean(const JSON_Object *object, const char *name);

/* dotget functions enable addressing values with dot notation in nested objects,
 just like in structs or c++/java/c# objects (e.g. objectA.objectB.value).
 Because valid names in JSON can contain dots, some values may be inaccessible
 this way. */
JSON_Value  * json_object_dotget_value  (const JSON_Object *object, const char *name);
const char  * json_object_dotget_string (const JSON_Object *object, const char *name);
JSON_Object * json_object_dotget_object (const JSON_Object *object, const char *name);
JSON_Array  * json_object_dotget_array  (const JSON_Object *object, const char *name);
double        json_object_dotget_number (const JSON_Object *object, const char *name);
int           json_object_dotget_boolean(const JSON_Object *object, const char *name);

/* Functions to get available names */
size_t        json_object_get_count(const JSON_Object *object);
const char  * json_object_get_name (const JSON_Object *object, size_t index);
    
/* JSON Array */
JSON_Value  * json_array_get_value  (const JSON_Array *array, size_t index);
const char  * json_array_get_string (const JSON_Array *array, size_t index);
JSON_Object * json_array_get_object (const JSON_Array *array, size_t index);
JSON_Array  * json_array_get_array  (const JSON_Array *array, size_t index);
double        json_array_get_number (const JSON_Array *array, size_t index);
int           json_array_get_boolean(const JSON_Array *array, size_t index);
size_t        json_array_get_count  (const JSON_Array *array);

/* JSON Value */
JSON_Value_Type json_value_get_type   (const JSON_Value *value);
JSON_Object *   json_value_get_object (const JSON_Value *value);
JSON_Array  *   json_value_get_array  (const JSON_Value *value);
const char  *   json_value_get_string (const JSON_Value *value);
double          json_value_get_number (const JSON_Value *value);
int             json_value_get_boolean(const JSON_Value *value);
void            json_value_free       (JSON_Value *value);
int json_get_item(char buf_in[], int *start, int *end, char key[], char buf_out[], int max_size);
    
#ifdef __cplusplus
}
#endif

#endif
