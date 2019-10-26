const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style type="text/css">
button {
    color: #444444;
    background: #F3F3F3;
    border: 1px #DADADA solid;
    padding: 5px 10px;
    border-radius: 2px;
    font-weight: bold;
    font-size: 9pt;
    outline: none;
}

button:hover {
    border: 1px #C6C6C6 solid;
    box-shadow: 1px 1px 1px #EAEAEA;
    color: #333333;
    background: #F7F7F7;
}

button:active {
    box-shadow: inset 1px 1px 1px #DFDFDF;   
}



/* Red Google Button as seen on drive.google.com */
button.red {
    background: -webkit-linear-gradient(top, #DD4B39, #D14836); 
    background: -moz-linear-gradient(top, #DD4B39, #D14836); 
    background: -ms-linear-gradient(top, #DD4B39, #D14836); 
    border: 1px solid #DD4B39;
    color: white;
    text-shadow: 0 1px 0 #C04131;
}

button.red:hover {
     background: -webkit-linear-gradient(top, #DD4B39, #C53727);
     background: -moz-linear-gradient(top, #DD4B39, #C53727);
     background: -ms-linear-gradient(top, #DD4B39, #C53727);
     border: 1px solid #AF301F;
}

button.red:active {
     box-shadow: inset 0 1px 1px rgba(0,0,0,0.2);
    background: -webkit-linear-gradient(top, #D74736, #AD2719);
    background: -moz-linear-gradient(top, #D74736, #AD2719);
    background: -ms-linear-gradient(top, #D74736, #AD2719);
}

html,
body {
  height: 100%;
}
body {
  background-color: #1a1a1a;
  font-family: sans-serif;
  font-size: 15px;
  color: #ccc;
}
input[type="text"] {
  background-color: transparent;
  margin-top: 30px;
  border: 0;
  border-bottom: solid 1px #8080ff;
  text-align: center;
  font-size: 20px;
  color: #518bf0;
  text-shadow: 0 0 3px #518bf0;
  width: 45px;
  display: inline-block;
}
input:focus {
  outline: 0;
  border-bottom: dashed 1px #ff8080;
}
input::-moz-selection {
  color: #1a1a1a;
  background-color: #c6e4ee;
}
input::selection {
  color: #1a1a1a;
  background-color: #c6e4ee;
}
::-webkit-input-placeholder {
  color: #7aa6f3;
  text-shadow: 0 0 3px #7aa6f3;
}
:-moz-placeholder {
  color: #7aa6f3;
  text-shadow: 0 0 3px #7aa6f3;
}
::-moz-placeholder {
  color: #7aa6f3;
  text-shadow: 0 0 3px #7aa6f3;
}
:-ms-input-placeholder {
  color: #7aa6f3;
  text-shadow: 0 0 3px #7aa6f3;
}
.wrapper {
  display: -ms-flexbox;
  display: box;
  display: flex;
  -o-box-align: center;
  align-items: center;
  -o-box-pack: center;
  justify-content: center;
  -o-box-orient: vertical;
  flex-direction: column;
  height: 100%;
}
.green {
  margin-top: 15px;
}
.green .progress,
.red .progress,
.orange .progress {
  position: relative;
  border-radius: 50%;
}
.green .progress,
.red .progress,
.orange .progress {
  width: 250px;
  height: 250px;
}
.green .progress {
  border: 5px solid #53fc53;
}
.green .progress {
  box-shadow: 0 0 20px #029502;
}
.green .progress,
.red .progress,
.orange .progress {
  transition: all 1s ease;
}
.green .progress .inner,
.red .progress .inner,
.orange .progress .inner {
  position: absolute;
  overflow: hidden;
  z-index: 2;
  border-radius: 50%;
}
.green .progress .inner,
.red .progress .inner,
.orange .progress .inner {
  width: 240px;
  height: 240px;
}
.green .progress .inner,
.red .progress .inner,
.orange .progress .inner {
  border: 5px solid #1a1a1a;
}
.green .progress .inner,
.red .progress .inner,
.orange .progress .inner {
  transition: all 1s ease;
}
.green .progress .inner .water,
.red .progress .inner .water,
.orange .progress .inner .water {
  position: absolute;
  z-index: 1;
  width: 200%;
  height: 200%;
  left: -50%;
  border-radius: 40%;
  -webkit-animation-iteration-count: infinite;
  animation-iteration-count: infinite;
  -webkit-animation-timing-function: linear;
  animation-timing-function: linear;
  -webkit-animation-name: spin;
  animation-name: spin;
}
.green .progress .inner .water {
  top: 25%;
}
.green .progress .inner .water {
  background: rgba(83,252,83,0.5);
}
.green .progress .inner .water,
.red .progress .inner .water,
.orange .progress .inner .water {
  transition: all 1s ease;
}
.green .progress .inner .water,
.red .progress .inner .water,
.orange .progress .inner .water {
  -webkit-animation-duration: 10s;
  animation-duration: 10s;
}
.green .progress .inner .water {
  box-shadow: 0 0 20px #03bc03;
}
.green .progress .inner .glare,
.red .progress .inner .glare,
.orange .progress .inner .glare {
  position: absolute;
  top: -120%;
  left: -120%;
  z-index: 5;
  width: 200%;
  height: 200%;
  -webkit-transform: rotate(45deg);
  transform: rotate(45deg);
  border-radius: 50%;
}
.green .progress .inner .glare,
.red .progress .inner .glare,
.orange .progress .inner .glare {
  background-color: rgba(255,255,255,0.15);
}
.green .progress .inner .glare,
.red .progress .inner .glare,
.orange .progress .inner .glare {
  transition: all 1s ease;
}
.green .progress .inner .percent,
.red .progress .inner .percent,
.orange .progress .inner .percent {
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  font-weight: bold;
  text-align: center;
}
.green .progress .inner .percent,
.red .progress .inner .percent,
.orange .progress .inner .percent {
  line-height: 240px;
  font-size: 92.3076923076923px;
}
.green .progress .inner .percent {
  color: #03c603;
}
.green .progress .inner .percent {
  text-shadow: 0 0 10px #029502;
}
.green .progress .inner .percent,
.red .progress .inner .percent,
.orange .progress .inner .percent {
  transition: all 1s ease;
}
.red {
  margin-top: 15px;
}
.red .progress {
  border: 5px solid #ed3b3b;
}
.red .progress {
  box-shadow: 0 0 20px #7a0b0b;
}
.red .progress .inner .water {
  top: 75%;
}
.red .progress .inner .water {
  background: rgba(237,59,59,0.5);
}
.red .progress .inner .water {
  box-shadow: 0 0 20px #9b0e0e;
}
.red .progress .inner .percent {
  color: #a30f0f;
}
.red .progress .inner .percent {
  text-shadow: 0 0 10px #7a0b0b;
}
.orange {
  margin-top: 15px;
}
.orange .progress {
  border: 5px solid #f07c3e;
}
.orange .progress {
  box-shadow: 0 0 20px #7e320a;
}
.orange .progress .inner .water {
  top: 50%;
}
.orange .progress .inner .water {
  background: rgba(240,124,62,0.5);
}
.orange .progress .inner .water {
  box-shadow: 0 0 20px #a0400c;
}
.orange .progress .inner .percent {
  color: #a8430d;
}
.orange .progress .inner .percent {
  text-shadow: 0 0 10px #7e320a;
}
#copyright {
  margin-top: 25px;
  background-color: transparent;
  font-size: 14px;
  color: #b3b3b3;
  text-align: center;
}
#copyright div {
  margin-bottom: 10px;
}
#copyright a,
#copyright a:link {
  color: #808080;
  text-decoration: none;
  border-bottom: 1px solid #808080;
  padding-bottom: 2px;
}
#copyright a:active {
  color: #b3b3b3;
}
#copyright a:hover {
  color: #b3b3b3;
  border-bottom: 1px solid #b3b3b3;
  padding-bottom: 4px;
}
.instructions {
  display: inline-block;
  margin: 5px 0;
  font-size: 16px;
}
@-webkit-keyframes spin {
  from {
    -webkit-transform: rotate(0deg);
    transform: rotate(0deg);
  }
  to {
    -webkit-transform: rotate(360deg);
    transform: rotate(360deg);
  }
}
@keyframes spin {
  from {
    -webkit-transform: rotate(0deg);
    transform: rotate(0deg);
  }
  to {
    -webkit-transform: rotate(360deg);
    transform: rotate(360deg);
  }
}

</style>

<div class="wrapper">
  
  <span class="instructions" style="font-size:24px;">MJD Automation Systems</span>
  <span class="instructions" style="font-size:24px;"></span>
  <span class="instructions" style="font-size:24px;"></span>
  <span class="instructions" style="font-size:24px;"></span>
  <span class="instructions" style="font-size:24px;"></span>
  
  <div class="green">
    <div class="progress">
      <div class="inner">
        <div class="percent"><span>MJD</span></div>
        <div class="water"></div>
        <div class="glare"></div>
      </div>
    </div>
  </div>
 <br><br> 
  
<center>

<div style="font-family: 'Roboto Condensed', sans-serif;font-size:34px;paddig:0;">
  Water Consumption <br>Litre : <span id="ADCValue" style="font-color:#96D55E;">0</span><br>
<button class="red" type="button" onclick="sendData(1)">Switch ON</button>
  <button class="red" type="button" onclick="sendData(0)">Switch OFF</button>
<br>  <br> State is : <span id="LEDState">NA</span><br>
</div>
</center>

<div class="drop"></div>
  <div class="wave"></div>


</body>
<script>
function sendData(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED?LEDstate="+led, true);
  xhttp.send();
}
 
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
  
}, 2000); //2000mSeconds update rate
 
function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("ADCValue").innerHTML =
      this.responseText;

    }
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}

</script>
</html>
)=====";
