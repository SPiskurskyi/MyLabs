export function updateTimer() {
    const now = new Date();
    const options = {
        hour: '2-digit',
        minute: '2-digit',
        second: '2-digit',
        hour12: false
    };
    document.getElementById("timer").textContent = now.toLocaleTimeString('uk-UA', options);
}

export function startTimer() {
    setInterval(updateTimer, 1000);
    updateTimer();
}