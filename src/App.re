open State;

[@react.component]
let make = () => { 
  let (state,dispatch) = React.useReducer(reducer, initState);
  let {secounds, currentPhase, isTicking} = state;
  React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timer));
  });

  <div className="container">
    <Header secounds dispatch currentPhase/>
    <button onClick={_ => dispatch(TogglePhase)}>{React.string("Switch Timer")}</button>
    <Timer secounds maxTime={
      switch (currentPhase) {
        | Work => state.workTime * 60
        | Play => state.playTime * 60
      }
    }/>
    <button onClick={_ => dispatch(Stop)}>{React.string("Stop")}</button>
    <button onClick={_ => dispatch(Start)}>{React.string("Start")}</button>
    <button onClick={_ => dispatch(Reset)}>{React.string("Reset")}</button>
    <TimerActions dispatch isTicking/>
    <EditTime phase="Work" value={state.workTime} onChange={e => dispatch(SetTime(Work, e))}/>
    <EditTime phase="Play" value={state.playTime} onChange={e => dispatch(SetTime(Play, e))}/>

  </div>
};