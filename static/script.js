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

// Define Yoruba keywords for autocompletion
const yorubaKeywords = [
    { text: "ti", displayText: "ti (if)" },
    { text: "pari", displayText: "pari (end)" },
    { text: "se", displayText: "se (do)" },
    { text: "fi", displayText: "fi (set/put)" },
    { text: "dogba", displayText: "dogba (equals)" },
    { text: "nigbati", displayText: "nigbati (while)" },
    { text: "pada", displayText: "pada (return)" },
    { text: "ise", displayText: "ise (function)" },
    { text: "sope", displayText: "sope (print)" },
    { text: "si", displayText: "si (to)" },
    { text: "bibeeko", displayText: "bibeeko (else if)" },
    { text: "lati", displayText: "lati (from)" },
    { text: "fun", displayText: "fun (for)" },
    { text: "ifikun", displayText: "ifikun (addition)" },
    { text: "pe", displayText: "pe (call)" },
    { text: "ooto", displayText: "ooto (true)" },
    { text: "iro", displayText: "iro (false)" }
];

// Yoruba snippets for autocompletion
const yorubaSnippets = [
    { text: "ise(name, param)\n    \npari", displayText: "Function declaration" },
    { text: "ti condition se\n    \npari", displayText: "If statement" },
    { text: "ti condition se\n    \nbibeeko\n    \npari", displayText: "If-else statement" },
    { text: "nigbati condition se\n    \npari", displayText: "While loop" },
    { text: "fun i lati 1 de n se\n    \npari", displayText: "For loop" },
    { text: "pe(sope, \"\")", displayText: "Print statement" }
];

// Theme options
const themes = [
    { name: "Monokai", value: "monokai" },
    { name: "Dracula", value: "dracula" },
    { name: "Material", value: "material" },
    { name: "Nord", value: "nord" },
    { name: "Solarized Dark", value: "solarized dark" },
    { name: "Solarized Light", value: "solarized light" },
    { name: "Github", value: "github" },
    { name: "Vibrant Ink", value: "vibrant-ink" },
    { name: "Eclipse", value: "eclipse" },
    { name: "Elegant", value: "elegant" }
];

function initializeEditor() {
    // Initialize CodeMirror with additional features
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
            },
            "Ctrl-Space": "autocomplete"
        },
        styleActiveLine: true,
        value: "",
        autofocus: true,
        hintOptions: {
            hint: yorubaHint
        }
    });

    // Set editor size
    editor.setSize("70%", "400px");

    // Add change event handler
    editor.on("change", function() {
        // Mark as modified
        document.getElementById('statusMessage').textContent = 'Modified';
        // Save to local storage
        saveToLocalStorage('draft', editor.getValue());
    });
    
    // Set up autocompletion trigger
    editor.on("keyup", function(cm, event) {
        if (!cm.state.completionActive && 
            (event.keyCode > 64 && event.keyCode < 91) || // Letters
            (event.keyCode === 219) || // Opening bracket
            (event.keyCode === 40)) {  // Opening parenthesis
            CodeMirror.commands.autocomplete(cm);
        }
    });
    
    // Load last draft from local storage
    const savedDraft = loadFromLocalStorage('draft');
    if (savedDraft) {
        editor.setValue(savedDraft);
    }

    // Initialize theme selector
    initializeThemeSelector();
}

// Custom hint function for Yoruba language
function yorubaHint(editor) {
    const cursor = editor.getCursor();
    const line = editor.getLine(cursor.line);
    const start = cursor.ch;
    let end = cursor.ch;
    
    // Find the start of the current word
    while (start > 0 && /\w/.test(line.charAt(start - 1))) {
        start--;
    }
    
    // Get the current word
    const word = line.slice(start, end).toLowerCase();
    
    // Filter keywords and snippets based on the current word
    const filteredKeywords = yorubaKeywords.filter(kw => 
        kw.text.toLowerCase().startsWith(word)
    );
    
    const filteredSnippets = yorubaSnippets.filter(snip => 
        snip.displayText.toLowerCase().includes(word)
    );
    
    // Combine the results
    const completions = [...filteredKeywords, ...filteredSnippets];
    
    return {
        list: completions,
        from: CodeMirror.Pos(cursor.line, start),
        to: CodeMirror.Pos(cursor.line, end)
    };
}

// Initialize theme selector
function initializeThemeSelector() {
    // Create theme selector element
    const themeSelector = document.createElement('select');
    themeSelector.id = 'themeSelector';
    
    // Add theme options
    themes.forEach(theme => {
        const option = document.createElement('option');
        option.value = theme.value;
        option.textContent = theme.name;
        if (theme.value === 'monokai') {
            option.selected = true;
        }
        themeSelector.appendChild(option);
    });
    
    // Create label
    const themeLabel = document.createElement('span');
    themeLabel.textContent = 'Theme: ';
    
    // Create theme control group
    const themeGroup = document.createElement('div');
    themeGroup.className = 'control-group';
    themeGroup.appendChild(themeLabel);
    themeGroup.appendChild(themeSelector);
    
    // Add to the toolbar
    const toolbar = document.querySelector('.toolbar');
    toolbar.appendChild(themeGroup);
    
    // Add event listener
    themeSelector.addEventListener('change', function() {
        const selectedTheme = this.value;
        changeTheme(selectedTheme);
        saveToLocalStorage('theme', selectedTheme);
    });
    
    // Load saved theme
    const savedTheme = loadFromLocalStorage('theme');
    if (savedTheme) {
        themeSelector.value = savedTheme;
        changeTheme(savedTheme);
    }
}

// Change editor theme
function changeTheme(theme) {
    // Load the theme stylesheet if not already loaded
    loadThemeStylesheet(theme);
    
    // Apply the theme to the editor
    editor.setOption('theme', theme);
}

// Load theme stylesheet
function loadThemeStylesheet(theme) {
    const id = `codemirror-theme-${theme}`;
    
    // Check if already loaded
    if (!document.getElementById(id)) {
        const link = document.createElement('link');
        link.id = id;
        link.rel = 'stylesheet';
        link.href = `https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.65.2/theme/${theme}.min.css`;
        document.head.appendChild(link);
    }
}

// Save file functionality
function saveFile() {
    const code = editor.getValue();
    if (!code.trim()) {
        showNotification('Nothing to save. Editor is empty.', 'warning');
        return;
    }
    
    // Show save dialog
    const filename = prompt("Enter a filename to save (without extension):", "yoruba_program");
    if (!filename) return;
    
    // Create a blob and download link
    const blob = new Blob([code], { type: 'text/plain' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = `${filename}.ek`;
    document.body.appendChild(a);
    a.click();
    
    // Cleanup
    setTimeout(() => {
        document.body.removeChild(a);
        window.URL.revokeObjectURL(url);
    }, 0);
    
    document.getElementById('statusMessage').textContent = 'Saved';
    showNotification('File saved successfully!', 'success');
}

// New file functionality
function newFile() {
    if (editor.getValue().trim() !== '') {
        if (!confirm("You have unsaved changes. Are you sure you want to create a new file?")) {
            return;
        }
    }
    
    editor.setValue('');
    editor.focus();
    document.getElementById('statusMessage').textContent = 'New File';
    saveToLocalStorage('draft', '');
}

// Import file functionality
function importFile() {
    const input = document.createElement('input');
    input.type = 'file';
    input.accept = '.yorb,.txt';
    
    input.onchange = e => {
        const file = e.target.files[0];
        const reader = new FileReader();
        
        reader.onload = function(e) {
            const content = e.target.result;
            editor.setValue(content);
            editor.focus();
            document.getElementById('statusMessage').textContent = `Imported ${file.name}`;
            showNotification(`File ${file.name} imported successfully!`, 'success');
        };
        
        reader.readAsText(file);
    };
    
    input.click();
}

// Local storage helper functions
function saveToLocalStorage(key, value) {
    try {
        localStorage.setItem(`yoruba_editor_${key}`, value);
        return true;
    } catch (e) {
        console.error('Error saving to local storage:', e);
        return false;
    }
}

function loadFromLocalStorage(key) {
    try {
        return localStorage.getItem(`yoruba_editor_${key}`);
    } catch (e) {
        console.error('Error loading from local storage:', e);
        return null;
    }
}

// Notification system
function showNotification(message, type = 'info') {
    // Create notification element if it doesn't exist
    let notificationContainer = document.getElementById('notificationContainer');
    
    if (!notificationContainer) {
        notificationContainer = document.createElement('div');
        notificationContainer.id = 'notificationContainer';
        notificationContainer.style.position = 'fixed';
        notificationContainer.style.bottom = '20px';
        notificationContainer.style.right = '20px';
        notificationContainer.style.zIndex = '1000';
        document.body.appendChild(notificationContainer);
    }
    
    // Create notification
    const notification = document.createElement('div');
    notification.className = `notification notification-${type}`;
    notification.innerHTML = `
        <div class="notification-content">
            <i class="fas ${type === 'success' ? 'fa-check-circle' : type === 'warning' ? 'fa-exclamation-triangle' : 'fa-info-circle'}"></i>
            <span>${message}</span>
        </div>
        <button class="close-btn"><i class="fas fa-times"></i></button>
    `;
    
    // Style notification
    notification.style.backgroundColor = type === 'success' ? '#4caf50' : type === 'warning' ? '#ff9800' : '#2196f3';
    notification.style.color = 'white';
    notification.style.padding = '10px';
    notification.style.marginBottom = '10px';
    notification.style.borderRadius = '4px';
    notification.style.display = 'flex';
    notification.style.justifyContent = 'space-between';
    notification.style.alignItems = 'center';
    notification.style.boxShadow = '0 2px 5px rgba(0, 0, 0, 0.2)';
    notification.style.opacity = '0';
    notification.style.transition = 'opacity 0.3s ease-in-out';
    
    // Add close button event
    const closeBtn = notification.querySelector('.close-btn');
    closeBtn.addEventListener('click', () => {
        notification.style.opacity = '0';
        setTimeout(() => {
            notificationContainer.removeChild(notification);
        }, 300);
    });
    
    // Add to container and animate
    notificationContainer.appendChild(notification);
    setTimeout(() => {
        notification.style.opacity = '1';
    }, 10);
    
    // Auto remove after 5 seconds
    setTimeout(() => {
        if (notification.parentNode === notificationContainer) {
            notification.style.opacity = '0';
            setTimeout(() => {
                if (notification.parentNode === notificationContainer) {
                    notificationContainer.removeChild(notification);
                }
            }, 300);
        }
    }, 5000);
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
    document.getElementById('newFileButton').addEventListener('click', newFile);
    document.getElementById('saveButton').addEventListener('click', saveFile);
    document.getElementById('clearOutputButton').addEventListener('click', function() {
        document.getElementById('output').innerHTML = '';
    });
    
    // Add import button
    const importButton = document.createElement('button');
    importButton.id = 'importButton';
    importButton.innerHTML = '<i class="fas fa-file-upload"></i> Import';
    importButton.addEventListener('click', importFile);
    
    // Add to control group
    const fileControlGroup = document.getElementById('newFileButton').parentNode;
    fileControlGroup.insertBefore(importButton, document.getElementById('saveButton'));
    
    // Load CodeMirror addons for autocompletion
    loadScript('https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.65.2/addon/hint/show-hint.min.js');
    loadScript('https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.65.2/addon/hint/show-hint.min.css', true);
});

// Helper function to load scripts or stylesheets
function loadScript(src, isStylesheet = false) {
    const element = isStylesheet 
        ? document.createElement('link')
        : document.createElement('script');
        
    if (isStylesheet) {
        element.rel = 'stylesheet';
        element.href = src;
    } else {
        element.src = src;
    }
    
    document.head.appendChild(element);
}
