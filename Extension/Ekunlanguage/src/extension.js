const vscode = require('vscode');

function activate(context) {
    const keywords = [
        { label: 'ti', description: 'Starts a conditional statement' },
        { label: 'fi', description: 'Assignment keyword' },
        { label: 'si', description: 'Used for storing values' },
        { label: 'pari', description: 'Ends a block of code' },
        { label: 'pada', description: 'Return keyword' },
        { label: 'fun', description: 'For loop keyword' },
        { label: 'se', description: 'Indicates the start of a block' },
        { label: 'lati', description: 'To keyword, often used in loops' },
        { label: 'ise', description: 'Function definition keyword' },
        { label: 'nigbati', description: 'While loop keyword' },
        { label: 'bibeeko', description: 'Else-if keyword' },
    ];

    const provider = vscode.languages.registerCompletionItemProvider('ekun', {
        provideCompletionItems(document, position) {
            const completionItems = keywords.map(({ label, description }) => {
                const item = new vscode.CompletionItem(label, vscode.CompletionItemKind.Keyword);
                item.detail = description; // Adds a brief description next to the completion item
                item.documentation = new vscode.MarkdownString(`**${label}**: ${description}`);
                return item;
            });

            return completionItems;
        }
    });

    context.subscriptions.push(provider);
}

exports.activate = activate;

function deactivate() {}

module.exports = {
    activate,
    deactivate
};

