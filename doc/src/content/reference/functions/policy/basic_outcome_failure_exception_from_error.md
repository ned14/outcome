+++
title = "`auto basic_outcome_failure_exception_from_error(const EC &)`"
description = "."
+++

Synthesises an exception type from an error type. ADL discovered by the
{{% api "exception_type failure() const noexcept" %}} function. Default
overloads for this function are defined in Outcome for {{% api "std::error_code" %}}
and `boost::system::error_code`, these return `std::make_exception_ptr(std::system_error(ec))`
and `boost::copy_exception(boost::system::system_error(ec))` respectively.

*Overridable*: Argument dependent lookup.

*Requires*: Nothing.

*Namespace*: Namespace of `EC` type.

*Header*: `<outcome/std_outcome.hpp>`, `<outcome/boost_outcome.hpp>`
