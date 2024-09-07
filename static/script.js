let runFromJS;
let disassembleFromJS;

Module.onRuntimeInitialized = function() {
                runFromJS = Module.cwrap('run_from_js', 'string', ['string']);
                disassembleFromJS = Module.cwrap('disassemble_from_js', null, ['string']);
            };

function runCode() {
    const code = document.getElementById('highlightedCode').innerText;
    // Ensure the runtime is initialized and the function is wrapped
    if (runFromJS) {
        // Clear previous output
        document.getElementById('output').innerHTML = '';
        
        // Run the code
        const result = runFromJS(code);
    } else {
        document.getElementById('output').innerText = 'Runtime is not yet initialized.';
    }
}

function disassemble(){
    const code = document.getElementById('highlightedCode').innerText;
    if(disassembleFromJS){
        document.getElementById('output').innerHTML='';
        disassembleFromJS(code);
    }
    else{
        document.getElementById('output').innerText = "Runtime is not yet initialized.";
    }
}

document.getElementById('runCodeButton').addEventListener('click', runCode);
document.getElementById('disassembleButton').addEventListener('click', disassemble);



const keywords = ["ti", "pari", "se", "fi", "dogba", "nigbati", "pada", "ise", "sope", "si", "bibeeko", "lati", "fun", "ifikun", "pe", "ooto", "iro"];

