package net.askov.timecube;

import io.quarkus.logging.Log;
import io.smallrye.mutiny.Uni;

import javax.enterprise.context.ApplicationScoped;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@ApplicationScoped
public class TimeCubeService {

    private final Map<String, List<CubeEvent>> events = new HashMap<>();

    public Uni<String> newSideUp(String username, String side) {
        Log.infov("User '{0}' turned side {1} up",username, side);
        synchronized (events) { //TODO anything is better than this storage...
            List<CubeEvent> myEvents = events.getOrDefault(username, new ArrayList<>());
            myEvents.add(CubeEvent.builder()
                                  .side(side)
                                  .timestamp(LocalDateTime.now())
                                  .build());
            events.putIfAbsent(username, myEvents);
        }
        return Uni.createFrom().item(side);
    }

    public Uni<List<CubeEvent>> getHistory(String username) {
        return Uni.createFrom().item(events.getOrDefault(username, List.of()));
    }
}
