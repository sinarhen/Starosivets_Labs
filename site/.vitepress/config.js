import { defineConfig } from "vitepress"

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "Старосівець Богдан",
  description: "Завдання з ОП Старосівця Богдана ",

  // replace knu-template with name of your repository
  base: "/Starosivets_Labs/",

  themeConfig: {
    nav: [{ text: "Лабораторні", link: "/labs/lab_01/index" }],

    sidebar: [
      {
        text: "Лабораторні роботи",
        items: [{ text: "Лабораторна робота №1", link: "/labs/lab_01/index" }],
      },
    ],

    // socialLinks: [
    //   { icon: "github", link: "https://github.com/vuejs/vitepress" },
    // ],
  },
})
