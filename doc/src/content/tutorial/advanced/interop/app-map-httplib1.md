+++
title = "Mapping the HTTP library into the Application 1/2"
weight = 30
+++

Firstly we are going to need to wrap up `httplib::failure` into a custom
STL exception type before we can type erase it into an `exception_ptr`
instance. Please note that this code is defined in the `app` namespace:

{{% snippet "finale.cpp" "app_map_httplib1" %}}

The only real thing to note about `app::httplib_error` is that it squirrels away
the original `httplib::failure` in case that is ever needed. We do, of
course, need to create some sort of descriptive string for `std::runtime_error`
so its `.what()` returns a useful summary of the original failure. This
is the purpose of the `app::make_httplib_exception()` function.
