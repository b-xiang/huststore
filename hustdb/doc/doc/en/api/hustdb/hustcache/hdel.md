## hdel ##

**Interface:** `/hustcache/hdel`

**Method:** `GET`

**Parameter:** 

*  **tb** (Required)  
*  **key** (Required)  

**Sample A:**

    curl -i -X GET "http://localhost:8085/hustcache/hdel?tb=test_table&key=test_key"

**Result A1:**

	HTTP/1.1 404 Not Found
		
**Result A2:**

	HTTP/1.1 200 OK

[Previous](../hustcache.md)

[Home](../../../index.md)