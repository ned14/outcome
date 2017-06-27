{{ $snippet := split (readFile (printf "snippets/%s" (.Get 0))) (printf "//! [%s]" (.Get 1)) }}{{ highlight (index $snippet 1) "c++" "" }}
