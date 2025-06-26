# TÌM HIỂU VỀ JSON
- Khái niệm về Json
- Cách Json hoạt động
- Các hàm thao tác với Json trong C

# 1. KHÁI NIỆM
- JSON là viết tắt của "JavaScript Object Notation" (Ghi chú về Đối tượng JavaScript). Đây là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.
- JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp dựa trên cặp key - value, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.

## 2. DỮ LIỆU TRONG JSON
- Dữ liệu trong JSON được tổ chức dưới dạng **Features**, **Object** hoặc **Array**.
- Trong đó:
  - **Feature (thuộc tính)** là một cặp key - value với Key luôn là chuỗi (string), còn value có thể là bất kỳ kiểu dữ liệu JSON hợp lệ nào (string, number, boolean, array, object hoặc null).

```cpp
"Address": "Ho Chi Minh" 
```
Đây chỉ là một cặp key - value, thông thường Json sẽ được tổ chức thành một tổ hợp các cặp key - value này.

  - **Object (đối tượng)** trong JSON là một tập hợp các cặp **key - value** được đặt trong dấu {}. 
```cpp
{
  "name": "Nghia",
  "age": 19,
  "isStudent": true
}
```

Đây là một JSON Object vì nó chứa các cặp key - value.

  - **Array (mảng)** trong JSON là một danh sách các giá trị được đặt trong dấu []. Các giá trị này có thể thuộc bất kỳ kiểu dữ liệu JSON hợp lệ nào.

```cpp
[
  {
    "name": "Nghia",
    "age": 19
  },
  {
    "name": "Dung",
    "age": 25
  }
]
```

Đây là một JSON Array, chứa nhiều JSON Object

## 3. CÁCH TỔ CHỨC JSON
Json sẽ được tổ chức với các khái niệm JsonType, JsonValue, các hàm parse dùng để đọc dữ liệu.

## CẤU TRÚC JSON

## 3.1 JSON Type
- Đây là một biến enum (giả sử JsonType được định nghĩa ở đâu đó) để xác định loại dữ liệu mà JsonValue đang lưu trữ.
- Ví dụ về JsonType:

```cpp
typedef enum
{
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;
```

## 3.2 Json Value
- JsonValue là một cấu trúc dữ liệu đại diện cho một giá trị JSON tại thời điểm đọc, với khả năng lưu trữ nhiều loại dữ liệu khác nhau (số, chuỗi, boolean, mảng, đối tượng). Khi **parser JSON đọc dữ liệu tuần tự**, mỗi giá trị được phát hiện sẽ được **biểu diễn bằng một JsonValue riêng biệt**, có kiểu dữ liệu tương ứng với nội dung của JSON.
- Cấu trúc của Json Value:

```cpp
typedef struct JsonValue
{
    JsonType type;
    union
    {
        int boolean;
        double number;
        char *string;
        struct
        {
            struct JsonValue *values;
            size_t count;
        } array;
        struct
        {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;
```

Vì bản chất khi đọc dữ liệu thì Json sẽ xử lý từng giá trị một, nên khi khai báo struct JsonValue ta kết hợp dùng **union** để tối bộ nhớ.

## THAO TÁC VỚI JSON
- Các hàm parse dùng để đọc, xử lý các kiểu dữ liệu khác nhau. Mỗi hàm sẽ có một cách xử lý khác nhau.

## 3.3 Cấu trúc dữ liệu đầu vào
- Trước tiên ta cần tìm hiểu về dữ liệu đầu vào để xử lý Json.
- Dữ liệu sẽ bao gồm một chuỗi các kỹ tự, nhiệm vụ của hàm Parse đó chính là xử lý các chuỗi này để đọc và chuyển nó về các kiểu dữ liệu tương ứng.
- Ví dụ như nếu chuỗi là "12" thì nhiệm vụ của hàm parse là đưa giá trị này về kiểu dữ liệu number.


```cpp
const char *json_str = "{"
                           "\"1001\":{"
                           "\"SoPhong\":3,"
                           "\"NguoiThue\":{"
                           "\"Ten\":\"Nguyen Van A\","
                           "\"CCCD\":\"1920517781\","
                           "\"Tuoi\":26,"
                           "\"ThuongTru\":{"
                           "\"Duong\":\"73 Ba Huyen Thanh Quan\","
                           "\"Phuong_Xa\":\"Phuong 6\","
                           "\"Tinh_TP\":\"Ho Chi Minh\""
                           "}"
                           "},"
                           "\"SoNguoiO\":{"
                           "\"1\":\"Nguyen Van A\","
                           "\"2\":\"Nguyen Van B\","
                           "\"3\":\"Nguyen Van C\""
                           "},"
                           "\"TienDien\": [24, 56, 98],"
                           "\"TienNuoc\":30.000"
                           "},"
                           "\"1002\":{"
                           "\"SoPhong\":5,"
                           "\"NguoiThue\":{"
                           "\"Ten\":\"Phan Hoang Trung\","
                           "\"CCCD\":\"012345678912\","
                           "\"Tuoi\":24,"
                           "\"ThuongTru\":{"
                           "\"Duong\":\"53 Le Dai Hanh\","
                           "\"Phuong_Xa\":\"Phuong 11\","
                           "\"Tinh_TP\":\"Ho Chi Minh\""
                           "}"
                           "},"
                           "\"SoNguoiO\":{"
                           "\"1\":\"Phan Van Nhat\","
                           "\"2\":\"Phan Van Nhi\","
                           "\"2\":\"Phan Van Tam\","
                           "\"3\":\"Phan Van Tu\""
                           "},"
                           "\"TienDien\":23.000,"
                           "\"TienNuoc\":40.000"
                           "}"
                           "}";
```

## 3.4 Hàm parse_json
- Tìm hiểu về hàm parse_json. Hàm parse_json dùng để xác định các ký tự đặc biệt ứng với mỗi kiểu dữ liệu và gọi hàm parse tương ứng với kiểu dữ liệu đó.

```cpp

JsonValue *parse_json(const char **json)
{
    while (isspace(**json))
    {
        (*json)++;
    }

    switch (**json)
    {
    case 'n':
        return parse_null(json);
    case 't':
    case 'f':
        return parse_boolean(json);
    case '\"':
        return parse_string(json);
    case '[':
        return parse_array(json);
    case '{':
        return parse_object(json);
    default:
        if (isdigit(**json) || **json == '-')
        {
            return parse_number(json);
        }
        else
        {
            // Lỗi phân tích cú pháp
            return NULL;
        }
    }
}
```

## 3.5 Hàm skip_whitespace
- Hàm skip_whitespace dùng để đọc kĩ tự khoảng trắng và dịch lên kí tự tiếp theo.

```cpp
static void skip_whitespace(const char **json)
{
    while (isspace(**json))
    {
        (*json)++;
    }
}
```

## 3.6 Hàm parse_null
- Hàm parse_null dùng để xác định kiểu dữ liệu null.

```cpp
JsonValue *parse_null(const char **json)
{
    skip_whitespace(json);
    if (strncmp(*json, "null", 4) == 0)
    {
        JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        *json += 4;
        return value;
    }
    return NULL;
}
```


## 3.7 Hàm parse_boolen
- Hàm parse_boolen dùng để xác định kiểu dữ liệu boolen.

```cpp
JsonValue *parse_boolean(const char **json)
{
    skip_whitespace(json);
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    if (strncmp(*json, "true", 4) == 0)
    {
        value->type = JSON_BOOLEAN;
        value->value.boolean = true;
        *json += 4;
    }
    else if (strncmp(*json, "false", 5) == 0)
    {
        value->type = JSON_BOOLEAN;
        value->value.boolean = false;
        *json += 5;
    }
    else
    {
        free(value);
        return NULL;
    }
    return value;
}
```

## 3.8 Hàm parse_number
- Hàm parse_number dùng để xác định kiểu dữ liệu number.

```cpp
JsonValue *parse_number(const char **json)
{
    skip_whitespace(json);
    char *end;

    double num = strtod(*json, &end);
    if (end != *json)
    {
        JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->value.number = num;
        *json = end;
        return value;
    }
    return NULL;
}
```

## 3.9 Hàm parse_string
- Hàm parse_string dùng để xác định kiểu dữ liệu string.

```cpp
JsonValue *parse_string(const char **json)
{
    skip_whitespace(json);

    if (**json == '\"')
    {
        (*json)++;
        const char *start = *json;
        while (**json != '\"' && **json != '\0')
        {
            (*json)++;
        }
        if (**json == '\"')
        {
            size_t length = *json - start; // 3
            char *str = (char *)malloc((length + 1) * sizeof(char));
            strncpy(str, start, length);
            str[length] = '\0';

            JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
            value->type = JSON_STRING;
            value->value.string = str;
            (*json)++;
            return value;
        }
    }
    return NULL;
}
```

## 3.10 Hàm parse_array
- Hàm parse_array dùng để xác định kiểu dữ liệu array

```cpp
JsonValue *parse_array(const char **json)
{
    skip_whitespace(json);
    if (**json == '[')
    {
        (*json)++;
        skip_whitespace(json);

        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));
        array_value->type = JSON_ARRAY;
        array_value->value.array.count = 0;
        array_value->value.array.values = NULL;

        /*
        double arr[2] = {};
        arr[0] = 30;
        arr[1] = 70;
        */

        while (**json != ']' && **json != '\0')
        {
            JsonValue *element = parse_json(json); // 70
            if (element)
            {
                array_value->value.array.count++;
                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));
                array_value->value.array.values[array_value->value.array.count - 1] = *element;
                free(element);
            }
            else
            {
                break;
            }
            skip_whitespace(json);
            if (**json == ',')
            {
                (*json)++;
            }
        }
        if (**json == ']')
        {
            (*json)++;
            return array_value;
        }
        else
        {
            free_json_value(array_value);
            return NULL;
        }
    }
    return NULL;
}
```

## 3.11. Hàm parse_object
- Hàm parse_object dùng để xác định kiểu dữ liệu object.

```cpp
JsonValue *parse_object(const char **json)
{
    skip_whitespace(json);
    if (**json == '{')
    {
        (*json)++;
        skip_whitespace(json);

        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
        object_value->type = JSON_OBJECT;
        object_value->value.object.count = 0;
        object_value->value.object.keys = NULL;
        object_value->value.object.values = NULL;

        while (**json != '}' && **json != '\0')
        {
            JsonValue *key = parse_string(json);
            if (key)
            {
                skip_whitespace(json);
                if (**json == ':')
                {
                    (*json)++;
                    JsonValue *value = parse_json(json);
                    if (value)
                    {
                        object_value->value.object.count++;
                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;

                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
                        free(value);
                    }
                    else
                    {
                        free_json_value(key);
                        break;
                    }
                }
                else
                {
                    free_json_value(key);
                    break;
                }
            }
            else
            {
                break;
            }
            skip_whitespace(json);
            if (**json == ',')
            {
                (*json)++;
            }
        }
        if (**json == '}')
        {
            (*json)++;
            return object_value;
        }
        else
        {
            free_json_value(object_value);
            return NULL;
        }
    }
    return NULL;
}

```

## 3.12. Hàm free_json_value
- Hàm này dùng để giải phóng bộ nhớ động của JsonValue.

```cpp
void free_json_value(JsonValue *json_value)
{
    if (json_value == NULL)
    {
        return;
    }

    switch (json_value->type)
    {
    case JSON_STRING:
        free(json_value->value.string);
        break;

    case JSON_ARRAY:
        for (size_t i = 0; i < json_value->value.array.count; i++)
        {
            free_json_value(&json_value->value.array.values[i]);
        }
        free(json_value->value.array.values);
        break;

    case JSON_OBJECT:
        for (size_t i = 0; i < json_value->value.object.count; i++)
        {
            free(json_value->value.object.keys[i]);
            free_json_value(&json_value->value.object.values[i]);
        }
        free(json_value->value.object.keys);
        free(json_value->value.object.values);
        break;

    default:
        break;
    }
}
```

## 3.13. Hàm test
- Hàm dùng để xuất JsonValue đã đọc được.

```cpp
void test(JsonValue *json_value)
{
    if (json_value != NULL && json_value->type == JSON_OBJECT)
    {
        // Truy cập giá trị của các trường trong đối tượng JSON
        size_t num_fields = json_value->value.object.count;
        size_t num_fields2 = json_value->value.object.values->value.object.count;
        for (size_t i = 0; i < num_fields; ++i)
        {

            char *key = json_value->value.object.keys[i];
            JsonValue *value = &json_value->value.object.values[i];

            JsonType type = (int)(json_value->value.object.values[i].type);

            if (type == JSON_STRING)
            {
                printf("%s: %s\n", key, value->value.string);
            }

            if (type == JSON_NUMBER)
            {
                printf("%s: %f\n", key, value->value.number);
            }

            if (type == JSON_BOOLEAN)
            {
                printf("%s: %s\n", key, value->value.boolean ? "True" : "False");
            }

            if (type == JSON_OBJECT)
            {
                printf("%s: \n", key);
                test(value);
            }

            if (type == JSON_ARRAY)
            {
                printf("%s: ", key);
                for (int i = 0; i < value->value.array.count; i++)
                {
                    test(value->value.array.values + i);
                }
                printf("\n");
            }
        }
    }
    else
    {
        if (json_value->type == JSON_STRING)
        {
            printf("%s ", json_value->value.string);
        }

        if (json_value->type == JSON_NUMBER)
        {
            printf("%f ", json_value->value.number);
        }

        if (json_value->type == JSON_BOOLEAN)
        {
            printf("%s ", json_value->value.boolean ? "True" : "False");
        }

        if (json_value->type == JSON_OBJECT)
        {
            printf("%s: \n", json_value->value.object.keys);
            test(json_value->value.object.values);
        }
    }
}

```

## 3.14. Chương trình mẫu

```cpp
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum
{
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

typedef struct JsonValue
{
    JsonType type;
    union
    {
        int boolean;
        double number;
        char *string;
        struct
        {
            struct JsonValue *values;
            size_t count;
        } array;
        struct
        {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;

JsonValue *parse_json(const char **json);

void free_json_value(JsonValue *json_value);

static void skip_whitespace(const char **json)
{
    while (isspace(**json))
    {
        (*json)++;
    }
}

JsonValue *parse_null(const char **json)
{
    skip_whitespace(json);
    if (strncmp(*json, "null", 4) == 0)
    {
        JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        *json += 4;
        return value;
    }
    return NULL;
}

JsonValue *parse_boolean(const char **json)
{
    skip_whitespace(json);
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    if (strncmp(*json, "true", 4) == 0)
    {
        value->type = JSON_BOOLEAN;
        value->value.boolean = true;
        *json += 4;
    }
    else if (strncmp(*json, "false", 5) == 0)
    {
        value->type = JSON_BOOLEAN;
        value->value.boolean = false;
        *json += 5;
    }
    else
    {
        free(value);
        return NULL;
    }
    return value;
}

JsonValue *parse_number(const char **json)
{
    skip_whitespace(json);
    char *end;

    double num = strtod(*json, &end);
    if (end != *json)
    {
        JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->value.number = num;
        *json = end;
        return value;
    }
    return NULL;
}

JsonValue *parse_string(const char **json)
{
    skip_whitespace(json);

    if (**json == '\"')
    {
        (*json)++;
        const char *start = *json;
        while (**json != '\"' && **json != '\0')
        {
            (*json)++;
        }
        if (**json == '\"')
        {
            size_t length = *json - start; // 3
            char *str = (char *)malloc((length + 1) * sizeof(char));
            strncpy(str, start, length);
            str[length] = '\0';

            JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
            value->type = JSON_STRING;
            value->value.string = str;
            (*json)++;
            return value;
        }
    }
    return NULL;
}

JsonValue *parse_array(const char **json)
{
    skip_whitespace(json);
    if (**json == '[')
    {
        (*json)++;
        skip_whitespace(json);

        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));
        array_value->type = JSON_ARRAY;
        array_value->value.array.count = 0;
        array_value->value.array.values = NULL;

        /*
        double arr[2] = {};
        arr[0] = 30;
        arr[1] = 70;
        */

        while (**json != ']' && **json != '\0')
        {
            JsonValue *element = parse_json(json); // 70
            if (element)
            {
                array_value->value.array.count++;
                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));
                array_value->value.array.values[array_value->value.array.count - 1] = *element;
                free(element);
            }
            else
            {
                break;
            }
            skip_whitespace(json);
            if (**json == ',')
            {
                (*json)++;
            }
        }
        if (**json == ']')
        {
            (*json)++;
            return array_value;
        }
        else
        {
            free_json_value(array_value);
            return NULL;
        }
    }
    return NULL;
}

JsonValue *parse_object(const char **json)
{
    skip_whitespace(json);
    if (**json == '{')
    {
        (*json)++;
        skip_whitespace(json);

        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
        object_value->type = JSON_OBJECT;
        object_value->value.object.count = 0;
        object_value->value.object.keys = NULL;
        object_value->value.object.values = NULL;

        while (**json != '}' && **json != '\0')
        {
            JsonValue *key = parse_string(json);
            if (key)
            {
                skip_whitespace(json);
                if (**json == ':')
                {
                    (*json)++;
                    JsonValue *value = parse_json(json);
                    if (value)
                    {
                        object_value->value.object.count++;
                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;

                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
                        free(value);
                    }
                    else
                    {
                        free_json_value(key);
                        break;
                    }
                }
                else
                {
                    free_json_value(key);
                    break;
                }
            }
            else
            {
                break;
            }
            skip_whitespace(json);
            if (**json == ',')
            {
                (*json)++;
            }
        }
        if (**json == '}')
        {
            (*json)++;
            return object_value;
        }
        else
        {
            free_json_value(object_value);
            return NULL;
        }
    }
    return NULL;
}

JsonValue *parse_json(const char **json)
{
    while (isspace(**json))
    {
        (*json)++;
    }

    switch (**json)
    {
    case 'n':
        return parse_null(json);
    case 't':
    case 'f':
        return parse_boolean(json);
    case '\"':
        return parse_string(json);
    case '[':
        return parse_array(json);
    case '{':
        return parse_object(json);
    default:
        if (isdigit(**json) || **json == '-')
        {
            return parse_number(json);
        }
        else
        {
            // Lỗi phân tích cú pháp
            return NULL;
        }
    }
}

////////////

/////////////

void free_json_value(JsonValue *json_value)
{
    if (json_value == NULL)
    {
        return;
    }

    switch (json_value->type)
    {
    case JSON_STRING:
        free(json_value->value.string);
        break;

    case JSON_ARRAY:
        for (size_t i = 0; i < json_value->value.array.count; i++)
        {
            free_json_value(&json_value->value.array.values[i]);
        }
        free(json_value->value.array.values);
        break;

    case JSON_OBJECT:
        for (size_t i = 0; i < json_value->value.object.count; i++)
        {
            free(json_value->value.object.keys[i]);
            free_json_value(&json_value->value.object.values[i]);
        }
        free(json_value->value.object.keys);
        free(json_value->value.object.values);
        break;

    default:
        break;
    }
}

void test(JsonValue *json_value)
{
    if (json_value != NULL && json_value->type == JSON_OBJECT)
    {
        // Truy cập giá trị của các trường trong đối tượng JSON
        size_t num_fields = json_value->value.object.count;
        size_t num_fields2 = json_value->value.object.values->value.object.count;
        for (size_t i = 0; i < num_fields; ++i)
        {

            char *key = json_value->value.object.keys[i];
            JsonValue *value = &json_value->value.object.values[i];

            JsonType type = (int)(json_value->value.object.values[i].type);

            if (type == JSON_STRING)
            {
                printf("%s: %s\n", key, value->value.string);
            }

            if (type == JSON_NUMBER)
            {
                printf("%s: %f\n", key, value->value.number);
            }

            if (type == JSON_BOOLEAN)
            {
                printf("%s: %s\n", key, value->value.boolean ? "True" : "False");
            }

            if (type == JSON_OBJECT)
            {
                printf("%s: \n", key);
                test(value);
            }

            if (type == JSON_ARRAY)
            {
                printf("%s: ", key);
                for (int i = 0; i < value->value.array.count; i++)
                {
                    test(value->value.array.values + i);
                }
                printf("\n");
            }
        }
    }
    else
    {
        if (json_value->type == JSON_STRING)
        {
            printf("%s ", json_value->value.string);
        }

        if (json_value->type == JSON_NUMBER)
        {
            printf("%f ", json_value->value.number);
        }

        if (json_value->type == JSON_BOOLEAN)
        {
            printf("%s ", json_value->value.boolean ? "True" : "False");
        }

        if (json_value->type == JSON_OBJECT)
        {
            printf("%s: \n", json_value->value.object.keys);
            test(json_value->value.object.values);
        }
    }
}

int main(int argc, char const *argv[])
{
    // Chuỗi JSON đầu vào

    const char *json_str = "{"
                           "\"1001\":{"
                           "\"SoPhong\":3,"
                           "\"NguoiThue\":{"
                           "\"Ten\":\"Nguyen Van A\","
                           "\"CCCD\":\"1920517781\","
                           "\"Tuoi\":26,"
                           "\"ThuongTru\":{"
                           "\"Duong\":\"73 Ba Huyen Thanh Quan\","
                           "\"Phuong_Xa\":\"Phuong 6\","
                           "\"Tinh_TP\":\"Ho Chi Minh\""
                           "}"
                           "},"
                           "\"SoNguoiO\":{"
                           "\"1\":\"Nguyen Van A\","
                           "\"2\":\"Nguyen Van B\","
                           "\"3\":\"Nguyen Van C\""
                           "},"
                           "\"TienDien\": [24, 56, 98],"
                           "\"TienNuoc\":30.000"
                           "},"
                           "\"1002\":{"
                           "\"SoPhong\":5,"
                           "\"NguoiThue\":{"
                           "\"Ten\":\"Phan Hoang Trung\","
                           "\"CCCD\":\"012345678912\","
                           "\"Tuoi\":24,"
                           "\"ThuongTru\":{"
                           "\"Duong\":\"53 Le Dai Hanh\","
                           "\"Phuong_Xa\":\"Phuong 11\","
                           "\"Tinh_TP\":\"Ho Chi Minh\""
                           "}"
                           "},"
                           "\"SoNguoiO\":{"
                           "\"1\":\"Phan Van Nhat\","
                           "\"2\":\"Phan Van Nhi\","
                           "\"2\":\"Phan Van Tam\","
                           "\"3\":\"Phan Van Tu\""
                           "},"
                           "\"TienDien\":23.000,"
                           "\"TienNuoc\":40.000"
                           "}"
                           "}";

    // Phân tích cú pháp chuỗi JSON
    JsonValue *json_value = parse_json(&json_str);

    test(json_value);

    // Kiểm tra kết quả phân tích cú pháp

    // Giải phóng bộ nhớ được cấp phát cho JsonValue
    free_json_value(json_value);

    return 0;
}

```

output

```
1001: 
SoPhong: 3.000000
NguoiThue: 
Ten: Nguyen Van A
CCCD: 1920517781
Tuoi: 26.000000
ThuongTru: 
Duong: 73 Ba Huyen Thanh Quan
Phuong_Xa: Phuong 6
Tinh_TP: Ho Chi Minh
SoNguoiO:
1: Nguyen Van A
2: Nguyen Van B
3: Nguyen Van C
TienDien: 24.000000 56.000000 98.000000
TienNuoc: 30.000000
1002:
SoPhong: 5.000000
NguoiThue:
Ten: Phan Hoang Trung
CCCD: 012345678912
Tuoi: 24.000000
ThuongTru:
Duong: 53 Le Dai Hanh
Phuong_Xa: Phuong 11
Tinh_TP: Ho Chi Minh
SoNguoiO:
1: Phan Van Nhat
2: Phan Van Nhi
2: Phan Van Tam
3: Phan Van Tu
TienDien: 23.000000
TienNuoc: 40.000000
```
