open State;
open Utils;

[@react.component]
let make = (~secounds, ~currentPhase, ~dispatch) => {
  let label =
   secounds > 0
    ? switch (currentPhase) {
      | Work => "Time to Work"
      | Play => "Break time"
    } 
    : (
      switch (currentPhase) {
      | Work => "Ready for a break?"
      | Play => "Ready to start working?"
      }
    );
  
<h1 onClick={secounds == 0 ? _ => dispatch(TogglePhase) : (_=>())}>{s(label)}</h1>};