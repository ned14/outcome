# Tooling notes

Follow-ups on the review tooling itself, recorded from a run. Not code findings —
those live in `plans/analysis.md`.

## Extend the reviewer budget (noted 2026-10-24, operator request)

The default reviewer budget is 6 minutes per reviewer (`pi-review run` default
`--budget-min 6`) and it is too small for the largest review area.

Evidence from the 10-round review-only run over `32f203695d` (artefacts in
`/workspace/reviews/outcome-llm-fixes-20261024`): this repo had no stalls, but it
only survived because its five areas are smaller — 52 core headers against
quickcpplib's 54 heavier ones, and a 448-file `docs` area that is cheap to read
because prose costs less to scan than templates. The quickcpplib run of the same
day stalled 4 times out of 10 rounds on a single area.

Options when this is picked up: raise `--budget-min`, or size the budget per area
(file count / total bytes in the area's own globs) rather than globally. The
same fix should consider the 600s stall window, which fires before the budget
does for a reviewer that is thinking rather than emitting output.
