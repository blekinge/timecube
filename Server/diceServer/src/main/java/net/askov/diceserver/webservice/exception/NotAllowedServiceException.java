package net.askov.diceserver.webservice.exception;


import javax.ws.rs.core.Response;

/*
 * Custom web-exception class (401)
 */
public class NotAllowedServiceException extends ServiceException {

    //Constant fields for the OpenApi
    public static final String description = "NotAllowedServiceException";
    public static final String responseCode = "401";

    private static final long serialVersionUID = 27182821L;
    private static final Response.Status responseStatus = Response.Status.UNAUTHORIZED; //404

    public NotAllowedServiceException() {
        super(responseStatus);
    }

    public NotAllowedServiceException(String message) {
        super(message, responseStatus);
    }

    public NotAllowedServiceException(String message, Throwable cause) {
        super(message, cause, responseStatus);
    }

    public NotAllowedServiceException(Throwable cause) {
        super(cause, responseStatus);
    }

    public NotAllowedServiceException(String mimeType, Object entity) {
        super(mimeType, entity, responseStatus);
    }

    public NotAllowedServiceException(String mimeType, Object entity, Throwable cause) {
        super(mimeType, entity, cause, responseStatus);
    }
}

