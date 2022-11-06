package net.askov.timecube;

import lombok.Builder;
import lombok.Value;

import java.time.LocalDateTime;

@Value
@Builder
public class CubeEvent {
    String side;
    LocalDateTime timestamp;
}
