package net.askov.diceserver.webservice;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.fasterxml.jackson.jaxrs.json.JacksonJaxbJsonProvider;
import dk.kb.util.yaml.YAML;
import net.askov.diceserver.api.v1.impl.DiceServerApiServiceImpl;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;


public class Application_v1 extends javax.ws.rs.core.Application {
    private final Logger log = LoggerFactory.getLogger(getClass());

    //private final StorageDaoFactory daoFactory;
    //private final TripCoder tripCoder;
    //private final MarkdownRender markdownRenderer;


    public Application_v1() {
        log.info("Initializing WebQA service v{}", getClass().getPackage().getImplementationVersion());

        YAML serviceConfig;
        try {
            InitialContext ctx = new InitialContext();
            String configFile = (String) ctx.lookup("java:/comp/env/application-config");
            serviceConfig = YAML.resolveLayeredConfigs(configFile);
        } catch (IOException | NamingException e) {
            throw new RuntimeException("Failed to lookup settings", e);
        }
        //daoFactory = new StorageDaoFactory(serviceConfig);
        //tripCoder = new TripCoder();
        //markdownRenderer = new MarkdownRender();
    }


    //public StorageDaoFactory getDaoFactory() {
    //    return daoFactory;
    //}
    //
    //public MarkdownRender getMarkdownRender(){
    //    return markdownRenderer;
    //}
    //
    //public TripCoder getTripCoder() {
    //    return tripCoder;
    //}

    //    TODO markdown renderer directly as provider??
    @Override
    public Set<Class<?>> getClasses() {
        return new HashSet<>(Arrays.asList(DiceServerApiServiceImpl.class, ServiceExceptionMapper.class));
    }

    @Override
    public Set<Object> getSingletons() {
        // see https://github.com/FasterXML/jackson-modules-java8
        ObjectMapper mapper = new ObjectMapper();

        mapper.findAndRegisterModules();
        mapper.disable(SerializationFeature.INDENT_OUTPUT);

        JacksonJaxbJsonProvider jacksonJaxbJsonProvider = new JacksonJaxbJsonProvider(mapper,
                                                                                      JacksonJaxbJsonProvider.DEFAULT_ANNOTATIONS);

        return Set.of(jacksonJaxbJsonProvider);
    }

}
