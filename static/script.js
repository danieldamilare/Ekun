let runFromJS;
let disassembleFromJS;
let editor;

// Define the Yoruba mode for syntax highlighting
CodeMirror.defineMode("yoruba", function() {
    return {
        token: function(stream, state) {
            // Keywords in Yoruba
            const keywords = ["ti", "pari", "se", "fi", "dogba", "nigbati", "pada", 
                            "ise", "sope", "si", "bibeeko", "lati", "fun", "ifikun", 
                            "pe", "ooto", "iro"];
            
            // Skip spaces
            if (stream.eatSpace()) return null;
            
            // Comments
            if (stream.match("(*")) {
                state.inComment = true;
                return "comment";
            }
            
            if (state.inComment) {
                if (stream.match("*)")) {
                    state.inComment = false;
                } else {
                    stream.next();
                }
                return "comment";
            }
            
            // Strings
            if (stream.match(/"(?:[^"\\]|\\.)*"/)) {
                return "string";
            }
            
            // Numbers
            if (stream.match(/^-?\d*\.?\d+/)) {
                return "number";
            }
            
            // Keywords
            let word = stream.match(/^\w+/);
            if (word && keywords.includes(word[0])) {
                return "keyword";
            }
            
            stream.next();
            return null;
        },
        
        startState: function() {
            return { inComment: false };
        }
    };
});

function initializeEditor() {
    // Initialize CodeMirror
    editor = CodeMirror(document.getElementById('codeContainer'), {
        mode: "yoruba",
        theme: "monokai",
        lineNumbers: true,
        autoCloseBrackets: true,
        matchBrackets: true,
        indentUnit: 4,
        tabSize: 4,
        indentWithTabs: false,
        lineWrapping: true,
        foldGutter: true,
        gutters: ["CodeMirror-linenumbers", "CodeMirror-foldgutter"],
        extraKeys: {
            "Tab": function(cm) {
                if (cm.somethingSelected()) {
                    cm.indentSelection("add");
                } else {
                    cm.replaceSelection("    ", "end");
                }
            }
        },
        styleActiveLine: true,
        value: "",
        autofocus: true
    });

    // Set editor size
    editor.setSize("70%", "400px");

    // Add change event handler
    editor.on("change", function() {
        // You can add any additional handling here
        document.getElementById('statusMessage').textContent = 'Modified';
    });
}

Module.onRuntimeInitialized = function() {
    runFromJS = Module.cwrap('run_from_js', 'string', ['string']);
    disassembleFromJS = Module.cwrap('disassemble_from_js', null, ['string']);
};

function runCode() {
    const code = editor.getValue();
    if (runFromJS) {
        document.getElementById('output').innerHTML = '';
        const result = runFromJS(code);
        document.getElementById('statusMessage').textContent = "Code run successfully!";
    } else {
        document.getElementById('output').innerText = 'Runtime is not yet initialized.';
    }
}

function disassemble() {
    const code = editor.getValue();
    if (disassembleFromJS) {
        document.getElementById('output').innerHTML = '';
        disassembleFromJS(code);
        document.getElementById('statusMessage').textContent = "Disassembled successfully!";
    } else {
        document.getElementById('output').innerText = "Runtime is not yet initialized.";
    }
}

// Example programs
const examples = {
    "Hello World": 'pe(sope, "E Kaabo aye!")',
    
    "Fibonacci": `ise(fibonacci, n)
    ti n < 2 se
        pada: n
    pari
    pada: pe(fibonacci, (n -1)) + pe(fibonacci, (n -2))
pari

fun i lati 1 de 20 se
    pe(sope, "fibonaci", i, "je", pe(fibonacci, i))
pari`,

    "Factorial Function": `ise(factorial, n)
    ti n dogba 1 se
        pada: 1
    pari
    pada: n * pe(factorial, n-1)
pari

pe(sope, pe(factorial, 10))`,

    "Fizzbuzz": `ise(fizzbuzz, n)
   fi 1 si i
   nigbati i <= n  se
        ti i % 15 == 0 se
           pe(sope, "fizzbuzz")
        bibeeko ti i % 5 == 0 se
           pe(sope, "buzz")
        bibeeko ti i % 3 == 0 se
           pe(sope, "fizz")
        bibeeko
           pe(sope, i)
        pari
        i = i + 1
     pari
pari

pe(fizzbuzz, 20)`,

    "Fractals": `(*
A program to generate mandelbrot set
*)
fi 0 si pixel1
nigbati pixel1 <= 24 se
    fi pixel1/12 - 1 si y
    fi 0 si j
    nigbati j <= 80 se
        fi j / 30 - 2 si x
        fi x si x0
        fi y si y0
        fi 0 si iter
        nigbati iter < 11 ati x0 * x0 + y0 * y0 <= 4 se
            fi (x0 * x0) - (y0 * y0) + x si x1
            fi 2 * x0 * y0 + y si y1
            fi x1 si x0
            fi y1 si y0
            fi iter + 1 si iter
        pari
        pe(ko_oro, " .-:;+=xX$& "[iter])
        fi j + 1 si j
    pari
    pe(sope)
    fi pixel1 + 1 si pixel1
pari`
};

document.addEventListener("DOMContentLoaded", function() {
    // Initialize CodeMirror
    initializeEditor();
    
    const exampleSelector = document.getElementById("exampleSelector");
    const loadExampleButton = document.getElementById("loadExampleButton");
    
    // Populate examples dropdown
    for (const key in examples) {
        const option = document.createElement("option");
        option.value = key;
        option.textContent = key;
        exampleSelector.appendChild(option);
    }
    
    // Load example handler
    loadExampleButton.addEventListener("click", function() {
        const selectedExample = exampleSelector.value;
        if (selectedExample && examples[selectedExample]) {
            editor.setValue(examples[selectedExample]);
            editor.focus();
        }
    });
    
    // Add event listeners for buttons
    document.getElementById('runCodeButton').addEventListener('click', runCode);
    document.getElementById('disassembleButton').addEventListener('click', disassemble);
    document.getElementById('newFileButton').addEventListener('click', function() {
        editor.setValue('');
        editor.focus();
    });
    document.getElementById('clearOutputButton').addEventListener('click', function() {
        document.getElementById('output').innerHTML = '';
    });
});
