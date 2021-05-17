type phase = 
  | Work
  | Play;

type state = {
  secounds: int,
  isTicking: bool,
  workTime: int,
  playTime: int,
  currentPhase: phase
}

type action = 
  | Start
  | Stop
  | Reset
  | Tick
  | TogglePhase
  | SetTime(phase, int);


let initState = {
  secounds:0,
  isTicking:false,
  workTime: 25,
  playTime:5,
  currentPhase:Work,
} 
let reducer = (state,action) =>
  switch (action) {
  | Start => {...state, isTicking:true}
  | Stop => {...state, isTicking:false}
  | Tick => state.isTicking && state.secounds > 0 ? {...state, secounds:state.secounds -1} : state
  | Reset => 
    switch(state.currentPhase) {
    | Work => {...state, secounds: state.workTime * 60}
    | Play => {...state, secounds: state.playTime * 60}
    }
  |SetTime(p,i) => 
    switch(p) {
    | Work => {...state,workTime:i}
    | Play => {...state, playTime:i}
    }
  | TogglePhase =>
  switch(state.currentPhase){
  | Work => {
    ...state,
    secounds: state.playTime * 60,
    currentPhase: Play,
    isTicking: true,
  }
  |Play => {
    ...state,
    secounds: state.workTime * 60,
    currentPhase:Work,
    isTicking: true,
  }
  }
  };