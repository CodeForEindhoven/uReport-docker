#!/bin/bash
curl -X POST -H 'Content-type:application/json' --data-binary '@schema.json' http://__SOLR_SERVER_HOSTNAME__:__SOLR_SERVER_PORT____SOLR_SERVER_PATH__/schema
curl "http://__SOLR_SERVER_HOSTNAME__:__SOLR_SERVER_PORT__/solr/admin/cores?action=RELOAD&core=__SOLR_CORE__"
