//! \brief Major version for cmake and DLL version stamping \ingroup config
#define OUTCOME_VERSION_MAJOR    2
//! \brief Minor version for cmake and DLL version stamping \ingroup config
#define OUTCOME_VERSION_MINOR    0
//! \brief Patch version for cmake and DLL version stamping \ingroup config
#define OUTCOME_VERSION_PATCH    0 
//! \brief Revision version for cmake and DLL version stamping \ingroup config
#define OUTCOME_VERSION_REVISION 0  // Revision version for cmake and DLL version stamping

//! \brief Defined between stable releases of Outcome. It means the inline namespace
//! will be permuted per-commit to ensure ABI uniqueness. \ingroup config
#ifndef OUTCOME_DISABLE_ABI_PERMUTATION
#define OUTCOME_UNSTABLE_VERSION
#endif
