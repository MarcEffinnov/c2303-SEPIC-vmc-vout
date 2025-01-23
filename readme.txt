When upgrading to X IDE 6.20 with XC-DSC 3.00, the following code changes have been introduced:

- function attributes ((always_inline)) has been depreciated and will trigger warnings as the compiler will ignore them (fixed by removing attributes)
- some NULL-pointer assignments to integer data members triggered warnings due to mismatching types (fixed by casting)
- while loop identation triggered warnings, indicating that compiler could not identify their purpose, barnig the risk of accidential removal (fixed by code reformatting)
- unused variables triggered warnings (fixed by disabling them, resp. reviewing/fixing their usage within functions)
- unified variable and data member declarations of form struct [nnn]_s to their default type [nnn]_t


