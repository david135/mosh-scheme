((element "manual-index" "-" "-" (element-content (seq one (name one "manual-index-front-matters") (name one "manual-index-contributions"))) "") (element "manual-index-front-matters" "-" "-" (element-content (seq one (name one "manual-index-title"))) "") (element "manual-index-title" "-" "-" (mixed-content (choice pcdata "div" "span")) "") (element "manual-index-contributions" "-" "-" (element-content (seq one (name zero-or-more "manual-index-contribution"))) "") (element "manual-index-contribution" "-" "-" empty "") (attribute "manual-index-front-matters" (("browser-type" ("one-step" "two-steps") "one-step") ("left-frame-width" "CDATA" "#IMPLIED") ("top-frame-height" "CDATA" "#IMPLIED") ("initial-manual-frame" ("blank" "info" "first-manual-contribution") "info") ("source-destination-delta" "CDATA" "html/") ("scheme-report-version" ("r4rs" "r5rs") "r5rs") ("scheme-report" ("none" "include" "merge") "none"))) (attribute "manual-index-contribution" (("informative-name" "CDATA" "#IMPLIED") ("path" "CDATA" "#IMPLIED") ("manual-file-path" "CDATA" "#IMPLIED") ("manual-url-path" "CDATA" "#IMPLIED"))) (attribute "manual-index-contributions" ()) (attribute "manual-index-title" ()) (attribute "manual-index" ()) (entity "XHTML-crossing" "(#PCDATA | div | span)*") (entity "URI" "CDATA") (entity "File-path" "CDATA") (entity "Number" "CDATA") (entity "Boolean" "(true | false)") (entity "Measure" "CDATA"))