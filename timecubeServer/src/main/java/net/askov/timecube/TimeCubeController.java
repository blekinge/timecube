package net.askov.timecube;

import io.smallrye.mutiny.Uni;

import javax.annotation.security.RolesAllowed;
import javax.inject.Inject;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.SecurityContext;
import java.util.List;

@Path("/")
public class TimeCubeController {

    @Inject
    TimeCubeService timeCubeService;

    @GET
    @Path("/history/")
    @RolesAllowed("User")
    @Produces("application/json" )
    public Uni<List<CubeEvent>> history(@Context SecurityContext securityContext){
        return timeCubeService.getHistory(securityContext.getUserPrincipal().getName());
    }

    @GET
    @Path("/side/{id}")
    @RolesAllowed("User")
    @Produces(MediaType.TEXT_PLAIN)
    public Uni<String> sideUp(@Context SecurityContext securityContext, @PathParam("id") String side){
        return timeCubeService.newSideUp(securityContext.getUserPrincipal().getName(),side);
    }
}
