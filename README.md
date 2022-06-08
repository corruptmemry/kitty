<pre>
KITTY
=====
The lightweight HTTP server on C

ROUTES
------
Routes are added in function void route() from file router.c

Sample GET route code:
<code>
GET("/test") {
    HTTP_200;
    printf("Hello World!");
}
</code>

Sample POST route code:
<code>
POST("/test") {
    HTTP_200;
    printf("Request size: %d bytes\n", payload_size);
    if (payload_size > 0)
        printf("Request body: %s", payload);
}
</code>

Please note, that printf function is used to send info to client.
Use fprintf for logging.
</pre>
