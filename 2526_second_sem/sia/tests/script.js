// ==UserScript==
// @name         Bulk Form Filler
// @namespace    http://tampermonkey.net/
// @version      2.0
// @description  Bulk paste questions from Markdown format and submit sequentially
// @match        https://urios.neolms.com/quiz_question_bank/new_question/*
// @grant        none
// ==/UserScript==

(function () {
  "use strict";

  const STORAGE_KEY = "quiz_batch_queue";

  // Fields mapping
  const fields = [
    "#question_description",
    "#text_1",
    "#text_2",
    "#text_3",
    "#text_4",
  ];

  function parseInput(text) {
    // 1. Split into major blocks by "---"
    const blocks = text
      .split(/---/)
      .map((b) => b.trim())
      .filter((b) => b);

    return blocks.map((block) => {
      // 2. For each block, split by the " - " delimiter
      const parts = block
        .split(/\s*-\s+/)
        .map((p) => p.trim())
        .filter((p) => p);

      // parts[0] is the question, parts[1-4] are options
      return parts;
    });
  }

  function processNext() {
    let queue = JSON.parse(sessionStorage.getItem(STORAGE_KEY) || "[]");

    if (queue.length === 0) {
      const data = prompt("No active queue. Paste Question + Options block:");
      if (!data) return;
      queue = parseInput(data);
    }

    const current = queue.shift();
    sessionStorage.setItem(STORAGE_KEY, JSON.stringify(queue));

    if (current && Array.isArray(current)) {
      // Fill fields
      fields.forEach((sel, i) => {
        const el = document.querySelector(sel);
        // Ensure we have a value for this field and current[i] is a string
        if (el && current[i]) el.value = current[i];
      });

      // Click "Save and add another"
      const submitBtn = document.querySelector(
        'a[href*="commit_and_another_same"]',
      );
      if (submitBtn) {
        setTimeout(() => submitBtn.click(), 500);
      } else {
        alert("Submit button not found. Queue cleared.");
        sessionStorage.removeItem(STORAGE_KEY);
      }
    } else if (current) {
      console.error("Queue item is not an array. Clearing storage.", current);
      sessionStorage.removeItem(STORAGE_KEY);
    }

    if (queue.length === 0) {
      console.log("Batch processing complete.");
    }
  }

  // Run on page load
  processNext();
})();
