# DiceServerApi

All URIs are relative to *http://localhost/diceServer/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**deleteArticle**](DiceServerApi.md#deleteArticle) | **DELETE** /side/{id} | 
[**getArticle**](DiceServerApi.md#getArticle) | **GET** /side/{id} | gets RenderedVersionOfPage
[**upsertArticle**](DiceServerApi.md#upsertArticle) | **PUT** /side/{id} | 


<a name="deleteArticle"></a>
# **deleteArticle**
> deleteArticle(id, tripCode)



### Example
```java
// Import classes:
import net.askov.diceserver.ApiClient;
import net.askov.diceserver.ApiException;
import net.askov.diceserver.Configuration;
import net.askov.diceserver.models.*;
import net.askov.diceserver.api.DiceServerApi;

public class Example {
  public static void main(String[] args) {
    ApiClient defaultClient = Configuration.getDefaultApiClient();
    defaultClient.setBasePath("http://localhost/diceServer/v1");

    DiceServerApi apiInstance = new DiceServerApi(defaultClient);
    String id = article-123A-v2; // String | The ID of the article to process
    String tripCode = "tripCode_example"; // String | 
    try {
      apiInstance.deleteArticle(id, tripCode);
    } catch (ApiException e) {
      System.err.println("Exception when calling DiceServerApi#deleteArticle");
      System.err.println("Status code: " + e.getCode());
      System.err.println("Reason: " + e.getResponseBody());
      System.err.println("Response headers: " + e.getResponseHeaders());
      e.printStackTrace();
    }
  }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **String**| The ID of the article to process |
 **tripCode** | **String**|  | [optional]

### Return type

null (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

### HTTP response details
| Status code | Description | Response headers |
|-------------|-------------|------------------|
**204** | Article deleted |  -  |
**401** | If the article was protected by a tripcode and you did not provide it |  -  |

<a name="getArticle"></a>
# **getArticle**
> String getArticle(id)

gets RenderedVersionOfPage

### Example
```java
// Import classes:
import net.askov.diceserver.ApiClient;
import net.askov.diceserver.ApiException;
import net.askov.diceserver.Configuration;
import net.askov.diceserver.models.*;
import net.askov.diceserver.api.DiceServerApi;

public class Example {
  public static void main(String[] args) {
    ApiClient defaultClient = Configuration.getDefaultApiClient();
    defaultClient.setBasePath("http://localhost/diceServer/v1");

    DiceServerApi apiInstance = new DiceServerApi(defaultClient);
    String id = article-123A-v2; // String | The ID of the article to process
    try {
      String result = apiInstance.getArticle(id);
      System.out.println(result);
    } catch (ApiException e) {
      System.err.println("Exception when calling DiceServerApi#getArticle");
      System.err.println("Status code: " + e.getCode());
      System.err.println("Reason: " + e.getResponseBody());
      System.err.println("Response headers: " + e.getResponseHeaders());
      e.printStackTrace();
    }
  }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **String**| The ID of the article to process |

### Return type

**String**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: text/html, text/markdown, application/json

### HTTP response details
| Status code | Description | Response headers |
|-------------|-------------|------------------|
**200** | OK |  -  |
**404** | Article ID is unknown |  -  |

<a name="upsertArticle"></a>
# **upsertArticle**
> String upsertArticle(id, body, tripCode)



### Example
```java
// Import classes:
import net.askov.diceserver.ApiClient;
import net.askov.diceserver.ApiException;
import net.askov.diceserver.Configuration;
import net.askov.diceserver.models.*;
import net.askov.diceserver.api.DiceServerApi;

public class Example {
  public static void main(String[] args) {
    ApiClient defaultClient = Configuration.getDefaultApiClient();
    defaultClient.setBasePath("http://localhost/diceServer/v1");

    DiceServerApi apiInstance = new DiceServerApi(defaultClient);
    String id = article-123A-v2; // String | The ID of the article to process
    String body = "body_example"; // String | The article contents
    String tripCode = "tripCode_example"; // String | 
    try {
      String result = apiInstance.upsertArticle(id, body, tripCode);
      System.out.println(result);
    } catch (ApiException e) {
      System.err.println("Exception when calling DiceServerApi#upsertArticle");
      System.err.println("Status code: " + e.getCode());
      System.err.println("Reason: " + e.getResponseBody());
      System.err.println("Response headers: " + e.getResponseHeaders());
      e.printStackTrace();
    }
  }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **String**| The ID of the article to process |
 **body** | **String**| The article contents |
 **tripCode** | **String**|  | [optional]

### Return type

**String**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: text/plain
 - **Accept**: text/html

### HTTP response details
| Status code | Description | Response headers |
|-------------|-------------|------------------|
**201** | Article created |  -  |
**204** | Article updated |  -  |
**401** | If the article was protected by a tripcode and you did not provide it |  -  |

